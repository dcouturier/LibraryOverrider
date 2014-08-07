package element;

public class Parameter {
	
	private String name = "", type;
	
	public Parameter(String type) {
		this.type = type;
	}
	
	public Parameter(String type, String name) {
		this.type = type;
		this.name = name;
	}
}
