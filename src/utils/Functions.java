package utils;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Functions {
	public static String readFileContent(File file) {
		try{
			FileReader fr = new FileReader(file);
			int len = 0;
			char[] buffer = new char[2048];
			StringBuilder strbldr = new StringBuilder();
			while((len = fr.read(buffer)) > 0) {
				strbldr.append(buffer, 0, len);
			}
			fr.close();
			return strbldr.toString();
		} catch(FileNotFoundException e) {
			return null;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	public static void cleanLines(String[] lines) {
		int len = lines.length;
		for(int i = 0; i < len; i++) {
			lines[i] = processLine(lines[i]);
		}
	}

	private static String processLine(String line) {
		//System.out.print("\"" + line + "\" in, \"");
		int ix = line.indexOf("//");
		if(ix >= 0) {
			line = line.substring(0, ix) + spaces(line.length() - ix);
		}
		//System.out.println(line + "\" out.");
		return line;
	}
	
	public static String spaces(int i) {
		char[] spaces = new char[i];
		for(int ix = 0; ix < i; ix++) spaces[ix] = ' ';
		return new String(spaces);
	}

	public static String aggregate(String[] lines, String sep) {
		if(lines.length > 0) {
		StringBuilder strbldr = new StringBuilder();
		int len = lines.length;
		for(int i = 0; i < len - 1; i ++) {
			strbldr.append(lines[i] + sep);
		}
		strbldr.append(lines[len - 1]);
		return strbldr.toString();
		} else return "";
	}
}
