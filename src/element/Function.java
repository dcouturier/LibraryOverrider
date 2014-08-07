package element;

import java.util.LinkedList;

public class Function {

	private LinkedList<Parameter> parameters = new LinkedList<Parameter>();
	private String name = "";
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void addParameter(Parameter param) {
		if(param.getName() == null) {
			param.setName("param_" + parameters.size());
		}
		this.parameters.addLast(param);
	}
}
