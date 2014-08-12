package element;

import java.util.Iterator;
import java.util.LinkedList;

public class Function {

	private LinkedList<Parameter> parameters = new LinkedList<Parameter>();
	private String name = "";
	private String returnType = "";
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setReturnType(String returnType) {
		this.returnType = returnType;
	}
	
	public void addParameter(Parameter param) {
		if(param.getName() == null) {
			param.setName("param_" + parameters.size());
		}
		this.parameters.addLast(param);
	}
	
	public String toString() {
		StringBuilder strbldr = new StringBuilder(returnType + " " + name + "(");
		Iterator<Parameter> params = parameters.iterator();
		
		
		while(params.hasNext()) {
			Parameter param = params.next();
			strbldr.append(param.getType() + " " + param.getName());
			
			if(params.hasNext()) {
				strbldr.append(", ");
			}
		}		
		strbldr.append(");");
		return strbldr.toString();
	}
}
