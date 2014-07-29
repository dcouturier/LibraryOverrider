package lex;

import java.io.File;
import java.rmi.UnexpectedException;
import java.util.LinkedList;

import utils.Functions;

public class FileCleaner {

	private String content;

	public FileCleaner(String fileContent) {
		this.content = fileContent;
	}

	public FileCleaner(File file) {
		if(file.exists()) {
			this.content = Functions.readFileContent(file);
		}
	}
	
	public void sanitizeContent() throws UnexpectedException {
		
		// Removing batch comments: (/* comment */)
		int ix = -1;
		int iy = 0;
		LinkedList<IntPair> batchComments = new LinkedList<IntPair>();
		while((ix = this.content.indexOf("/*", ix + 1)) >= 0) { // BatchComment starting
			iy = this.content.indexOf("*/", ix);
			if(iy >= 0) {
				batchComments.addLast(new IntPair(ix, iy));
			} else {
				throw new UnexpectedException("The file looks like it might be corrupted. (missing closing \"*/\".)");
			}
		}
		
		if(batchComments.size() > 0) {
			StringBuilder strbldr = new StringBuilder();
			ix = 0;
			for(IntPair pair : batchComments) {
				strbldr.append(content.substring(ix, pair.a));
				ix = pair.b +2;
			}
			strbldr.append(content.substring(ix));
			this.content = strbldr.toString();
		}
		
	}
	
	public String getContent() {
		return this.content;
	}
	
	public class IntPair {
		public int a, b;
		public IntPair(int a, int b) { this.a = a; this.b = b; }
	}
}
