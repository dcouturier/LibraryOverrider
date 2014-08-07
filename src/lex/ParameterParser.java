package lex;

import java.util.LinkedList;

public class ParameterParser {

	private LinkedList<String> params = new LinkedList<String>();
	private String t;
	private int ix = 0;
	private int last = 0;
	private Character ch = ' ';
	private int depth = 0;
	
	public ParameterParser(String parameterString) throws InvalidParameterException {
		this.t = parameterString;
		ch = t.charAt(ix);
		parseNext();
		
		System.out.println("hey!");
	}
	
	private void parseNext() throws InvalidParameterException {
		expression();
		
		if(ch == null) {
			params.addLast(t.substring(last, ix));
		} else if(ch == ',') {
			params.addLast(t.substring(last, ix));
			last = ix + 1;
			next();
			parseNext();
		}
	}
	
	
	private void next() throws InvalidParameterException {
		ix++;
		if(ix >= t.length()) {
			ch = null;
		} else {
			ch = t.charAt(ix);
		}
	}

	private void parenthesis() throws InvalidParameterException {
		depth++;
		expression();
		
		if(ch == ')') {
			depth--;
			next();
		} else {
			throw new InvalidParameterException("A closing parenthesis was expected.");
		}
	}
	
	private void expression() throws InvalidParameterException {
		boolean exitFlag = false;
		while(!exitFlag) {
			while(ch != null && isParameterText(ch) || (depth > 0 && ch == ',' /* Allow the comma if in a parenthesis (complex parameter...) */)) {
				next();
			}
			
			if(ch == null) {
				exitFlag = true;
			} else if(ch == '(') {
				next();
				parenthesis();
			} else if(ch == '*' && t.charAt(ix + 1) == '/') {
				next(); // Loads the *
				next(); // Loads the next char
				comment();
			} else {
				exitFlag = true;
			}
		}
	}
	
	private void comment() throws InvalidParameterException {
		if(ix + 1 >= t.length()) throw new InvalidParameterException("Missing a closing comment marker(\"*/\")");
		while(ch != '*' && t.charAt(ix + 1) != '/') {
			next();
			if(ix + 1 >= t.length()) throw new InvalidParameterException("Missing a closing comment marker(\"*/\")");
		}
		next();	// Loads the '/'
		next();	// Loads the next char
	}

	private boolean isParameterText(char ch) {
		return (ch >= 'A' && ch <= 'Z')	|| 
				(ch >= 'a' && ch <= 'z')	|| 
				(ch >= '0' && ch <= '9') ||
				ch == '_' || ch == '*' || ch == ' ' || ch == '&' || ch == '\n' || ch == '\t';
	}

	public String[] getParams() {
		return params.toArray(new String[params.size()]);
	}
}
