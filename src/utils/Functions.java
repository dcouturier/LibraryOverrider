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
		int ix = line.indexOf("//");
		if(ix >= 0) {
			line = line.substring(0, ix);
		}
		System.out.println(line);
		return line;
	}
}
