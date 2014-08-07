package lex;

import java.rmi.UnexpectedException;

import utils.Functions;
import utils.Pair;

public class FunctionParser {
	private String text;
	private String noCommentText;
	private String extern;
	
	private int start = 0, end = 0;
	
	public FunctionParser(String content, String extern) {
		this.text = content;
		this.extern = extern;
		
		FileCleaner cleaner = new FileCleaner(text);
		try {
			cleaner.sanitizeContent();
		} catch (UnexpectedException e) {
			e.printStackTrace();
		}
		this.noCommentText = cleaner.getContent();
		
		String[] lines = this.noCommentText.split("\n");
		Functions.cleanLines(lines);
		this.noCommentText = Functions.aggregate(lines, "\n");
		
	}
	
	public Pair<String, String> getNextFunction() {
		start = noCommentText.indexOf(extern, end);
		if(start < 0) return null;
		end = noCommentText.indexOf(';', end);
		if(end < 0) return null;
		end++;
		
		return new Pair<String,String>(text.substring(start, end), noCommentText.substring(start, end));
	}

}
