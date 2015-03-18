package element;

import java.util.Hashtable;
import java.util.Iterator;
import java.util.LinkedList;

public class Function {
	public static final String tracepoint_provider = "clust_provider";
	
		public static Hashtable<String,Integer> types = new Hashtable<String, Integer>();

		private LinkedList<Parameter> parameters = new LinkedList<Parameter>();
		private String name = "";
		private String returnType = "";

		public void setName(String name) {
			this.name = name;
		}

		public void setReturnType(String returnType) {
			this.returnType = returnType;
		}

		public String getName() {
			return this.name;
		}

		public String getReturnType() {
			return this.returnType;
		}

		public void addParameter(Parameter param) {
			if(param.getName() == null) {
				param.setName("param_" + parameters.size());
			}
			if(param.getType().equals("void")) return;

			else if(param.getType().contains("CL_CALLBACK *")) {  
				param.setType(param.getType().replaceAll("CL\\_CALLBACK \\*", "CL_CALLBACK * pfn_notify"));
			} else if (param.getType().equals("void (*user_func)(void *)")) {
				param.setName("user_func");
			}

			if(!types.containsKey(param.getType())) {
				types.put(param.getType(), 1);
			} else {
				types.put(param.getType(), types.get(param.getType()) + 1);
			}

			this.parameters.addLast(param);
		}

		private String getCoreHeader() {
			StringBuilder strbldr = new StringBuilder(returnType + " " + name + "(");
			Iterator<Parameter> params = parameters.iterator();


			while(params.hasNext()) {
				Parameter param = params.next();
				strbldr.append(param.getType() + " " + param.getName().replaceAll("pfn_notify", "").replaceAll("user_func", ""));

				if(params.hasNext()) {
					strbldr.append(", ");
				}
			}		
			strbldr.append(") ");
			return strbldr.toString();
		}

		public String toString() {
			return getCoreHeader() + ";";
		}

		public String getTracepointDeclaration() {
			//		StringBuilder strbldr = new StringBuilder("TRACEPOINT_EVENT(\n"
			//				+ "\t/* tracepoint provider name */\n"
			//				+ "\t" + tracepoint_provider + ",\n\n"
			//				+ "\t/* tracepoint/event name */\n"
			//				+ "\tclust_" + this.name + ",\n\n"
			//				+ "\tTP_ARGS(\n");
			//
			//		int paramSize = this.parameters.size();
			//		for(int i = 0; i < paramSize - 1; i++) {
			//			Parameter param = this.parameters.get(i);
			//			strbldr.append("\t\t" + param.getType() + ", " + param.getName() + ",\n");
			//		}		
			//
			//		// Add the last param without the coma
			//		if(paramSize > 0) {
			//			Parameter param = this.parameters.get(paramSize - 1);
			//			strbldr.append("\t\t" + param.getType() + ", " + param.getName() + "\n");
			//		}
			//
			//		// Adding this fields
			//		strbldr.append("\t),\n" 
			//				+ "\tTP_FIELDS(\n");
			//
			//		for(int i = 0; i < paramSize; i++) {
			//			Parameter param = this.parameters.get(i);
			//			String type = param.getType();
			//			String res = "ctf_integer";
			//			String value = param.getName();
			//			if(map.containsKey(type)) {
			//				res = map.get(type);
			//			}			
			//			strbldr.append("\t\t" + res + "(" + param.getType() + ", " + param.getName() + "_field, " + value + ")\n");
			//		}		
			//		strbldr.append("\t)\n"
			//				+ ")");
			//		return strbldr.toString();
			return "";
		}

		public String getInstrumentedFunctionCode() {
			int paramSize = this.parameters.size();

			boolean commDevice = this.name.contains("Enqueue") && containsParamTypeAndName("cl_event *", "event");
			StringBuilder strbldr = new StringBuilder();
			String core = getCoreHeader();
			core = core.replaceAll("\\[3\\]", "");

			strbldr.append(core + " {\n");
			
			if(this.name.equals("clCreateCommandQueue")) {
				strbldr.append("\tproperties |= CL_QUEUE_PROFILING_ENABLE;\n");
			}

			if(commDevice) {
				strbldr.append("\tbool toDelete = false;\n"
						+	"\tif(event == NULL) {\n"
						+	"#ifdef __DEBUG__\n"
						+	"\t\tfprintf(stdout, \"CLUST::" + this.name + ": Creating event dynamically...\\\\n\");\n"
						+	"#endif\n"
						+	"\t\tevent = malloc(sizeof(cl_event));\n"
						+	"\t\ttoDelete = true;\n"
						+	"\t}\n\n");
			}

			strbldr.append("\ttracepoint(" + tracepoint_provider + ", cl_" + this.getName()  + "_start");

			// API CALL parameters
			//		for(Parameter param: parameters) {
			//			strbldr.append(", " + param.getName());
			//		}

			strbldr.append(");\n");
			strbldr.append("\t" + this.returnType + " ret = reallib_" + this.name + "(");

			for(int i = 0; i < paramSize - 1; i++) {
				Parameter param = this.parameters.get(i);
				if(param.getName().contains("[3]")) {
					strbldr.append("&" + param.getName().replaceAll("\\[3\\]", "") + ", ");

				} else {
					strbldr.append(param.getName() + ", ");
				}
			}

			if(paramSize > 0) {
				Parameter param = this.parameters.get(paramSize - 1);
				if(param.getName().contains("[3]")) {
					strbldr.append("&" + param.getName().replaceAll("\\[3\\]", ""));

				} else {
					strbldr.append(param.getName());
				}
			}

			strbldr.append(");\n\ttracepoint(" + tracepoint_provider + ", cl_" + this.getName()  + "_end);\n");

			if(commDevice) {
				strbldr.append("\n\tint r = reallib_clSetEventCallback(*event, CL_COMPLETE, &eventCompleted, (toDelete)?&ev_delete:&ev_keep);\n"
						+"\tif(r != CL_SUCCESS) fprintf(stderr, \"CLUST::" + this.name + "->clSetEventCallback:error->%d\\\\n\", r);\n\n");
			}
			
			strbldr.append("\treturn ret;\n}");
			return strbldr.toString();
		}

		private boolean containsParamTypeAndName(String type, String name) {
			for(Parameter param : this.parameters) {
				if(param.getName().equals(name) && param.getType().equals(type)) {
					return true;
				}
			}
			return false;
		}

		public String getHeaderTypeDef() {
			StringBuilder strbldr = new StringBuilder("typedef " + this.returnType + " (*cl_api_call_" +  this.getName() + ") (");

			int paramSize = this.parameters.size();
			for(int i = 0; i < paramSize - 1; i++) {
				Parameter param = this.parameters.get(i);
				strbldr.append(param.getType() + " " + param.getName().replaceAll("pfn_notify", "").replaceAll("user_func", "") + ",");
			}

			if(paramSize > 0) {
				Parameter param = this.parameters.get(paramSize - 1);
				strbldr.append(param.getType() + " " + param.getName().replaceAll("pfn_notify", "").replaceAll("user_func", ""));
			}
			strbldr.append(");\nextern cl_api_call_" +  this.getName() + " reallib_" +  this.getName() + ";\n"
					+ "extern " + this.getCoreHeader().replaceAll("\\[3\\]", "") + ";");

			return strbldr.toString();
		}
}
