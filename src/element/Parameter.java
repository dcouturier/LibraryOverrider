package element;

public class Parameter {
	
	private String name = null, type;
	
	public Parameter(String type) {
		this.type = type;
	}
	
	public Parameter(String type, String name) {
		this.type = type;
		this.name = name;
	}
	
	public String getName() { 
		return this.name; 
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public String getType() {
		return this.type;
	}

	public void setType(String type) {
		this.type = type;
	}
}
