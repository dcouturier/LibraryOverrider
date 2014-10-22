package element;

import java.util.HashMap;
import java.util.Hashtable;
import java.util.Iterator;
import java.util.LinkedList;

public class Function {
	public static final String tracepoint_provider = "clust_provider";
	static final HashMap<String, String> map = new HashMap<String, String>() {/**
		 * 
		 */
		private static final long serialVersionUID = -6922446112927083855L;

	{
		put("cl_int", "ctf_integer");
	}};
	
	public static Hashtable<String,Integer> types = new Hashtable<String, Integer>();

	private LinkedList<Parameter> parameters = new LinkedList<Parameter>();
	private String name = "";
	private String returnType = "";
	private String suffix = "";

	public void setName(String name) {
		this.name = name;
	}

	public void setReturnType(String returnType) {
		this.returnType = returnType;
	}


	public void setSufix(String suffix) {
		this.suffix = suffix;
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
			strbldr.append(param.getType() + " " + param.getName());

			if(params.hasNext()) {
				strbldr.append(", ");
			}
		}		
		strbldr.append(") " + this.suffix);
		return strbldr.toString();
	}

	public String toString() {
		return getCoreHeader() + ";";
	}
	
	public String getTracepointDeclaration() {
		StringBuilder strbldr = new StringBuilder("TRACEPOINT_EVENT(\n"
				+ "\t/* tracepoint provider name */\n"
				+ "\t" + tracepoint_provider + ",\n\n"
				+ "\t/* tracepoint/event name */\n"
				+ "\tclust_" + this.name + ",\n\n"
				+ "\tTP_ARGS(\n");

		int paramSize = this.parameters.size();
		for(int i = 0; i < paramSize - 1; i++) {
			Parameter param = this.parameters.get(i);
			strbldr.append("\t\t" + param.getType() + ", " + param.getName() + ",\n");
		}		

		// Add the last param without the coma
		if(paramSize > 0) {
			Parameter param = this.parameters.get(paramSize - 1);
			strbldr.append("\t\t" + param.getType() + ", " + param.getName() + "\n");
		}

		// Adding this fields
		strbldr.append("\t),\n" 
				+ "\tTP_FIELDS(\n");

		for(int i = 0; i < paramSize; i++) {
			Parameter param = this.parameters.get(i);
			String type = param.getType();
			String res = "ctf_integer";
			String value = param.getName();
			if(map.containsKey(type)) {
				res = map.get(type);
			}			
			strbldr.append("\t\t" + res + "(" + param.getType() + ", " + param.getName() + "_field, " + value + ")\n");
		}		
		strbldr.append("\t)\n"
				+ ")");
		return strbldr.toString();
	}

	public String getInstrumentedFunctionCode() {
		int paramSize = this.parameters.size();
		StringBuilder strbldr = new StringBuilder();
		strbldr.append(getCoreHeader() + " {\n"
				+ "\ttracepoint(" + tracepoint_provider + ", clust_" + this.name);
				
		for(Parameter param: parameters) {
			strbldr.append(", " + param.getName());
		}

		strbldr.append(");\n"
				+ "\t" + this.returnType + " ret = reallib_" + this.name + "(");
		
		for(int i = 0; i < paramSize - 1; i++) {
			Parameter param = this.parameters.get(i);
			strbldr.append(param.getName() + ", ");
		}
		
		if(paramSize > 0) {
			Parameter param = this.parameters.get(paramSize - 1);
			strbldr.append(param.getName());
		}
		
		strbldr.append(");\n"
				+ "\treturn ret;\n}");
		return strbldr.toString();
	}
	
	public String getHeaderTypeDef() {
		StringBuilder strbldr = new StringBuilder("typdef " + this.returnType + " (*cl_api_call_" +  this.getName() + ") (");
		
		int paramSize = this.parameters.size();
		for(int i = 0; i < paramSize - 1; i++) {
			Parameter param = this.parameters.get(i);
			strbldr.append(param.getType() + " " + param.getName() + ",");
		}
		
		if(paramSize > 0) {
			Parameter param = this.parameters.get(paramSize - 1);
			strbldr.append(param.getType() + " " + param.getName());
		}
		strbldr.append(");\nextern cl_api_call_" +  this.getName() + " reallib_" +  this.getName() + ";\n"
				+ "extern " + this.getCoreHeader() + ";");
		
		return null;
	}
}
