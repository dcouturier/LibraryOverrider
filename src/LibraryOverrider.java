import java.io.File;
import java.rmi.UnexpectedException;

import lex.FileCleaner;
import utils.Functions;


public class LibraryOverrider {

	
	// Public static final constants
	public static final String APPLICATION_NAME = "Library Overrider";
	public static final String APPLICATION_JAR_NAME = "LibraryOverrider.jar";
	public static final String APPLICATION_DEVELOPPER = "David Couturier (david.couturier@polymtl.ca)";
	
	// Class attributes
	private File header = null;
	private String content = "";
	
	// Class methods

	public LibraryOverrider(File header) {
		this.header = header;
	}

	private void generateFiles() {
		this.content = Functions.readFileContent(this.header);
		FileCleaner cleaner = new FileCleaner(content);
		try {
			cleaner.sanitizeContent();
		} catch (UnexpectedException e) {
			e.printStackTrace();
		}
		this.content = cleaner.getContent();
		
		String[] lines = this.content.split("\n");
		Functions.cleanLines(lines);
	}
	
	
	// static Functions

		public static void main(String[] args) {
			
			File header = validateArgs(args);
			
			if(header != null) {
				new LibraryOverrider(header).generateFiles();
			} else {
				printHelp();
			}
		}


		private static File validateArgs(String[] args) {
			if(args.length < 1) {
				return null;
			}
			
			File header = new File(args[0]);
			if(header.exists()) {
				if(header.getName().endsWith(".h")) {
					return header;
				}
			}
			return null;
		}

		private static void printHelp() {
			System.out.println(APPLICATION_NAME + ": Help\n"
					+ "\tUsed to generate a C file with it's header that "
					+ "will override all of it's functions.\n"
					+ "\n\tUsage: java -jar " + APPLICATION_JAR_NAME + " /path/to/header/to/override.h\n\n"
							+ "Developped by " + APPLICATION_DEVELOPPER);
		}
		
	

}
