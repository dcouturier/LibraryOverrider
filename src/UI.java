import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.nio.file.Files;
import java.util.LinkedList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import lex.FunctionParser;
import lex.InvalidParameterException;
import lex.ParameterParser;
import utils.Pair;
import element.Function;
import element.Parameter;


public class UI extends JFrame {
	private static String functions_txt = "";
	
	public static final String F_NAME = "clust";

	JTextArea fMainTA; 
	JTextField fExternTF, fIgnoreKeywordListTF;
	/**
	 * 
	 */
	private static final long serialVersionUID = -7316827103620049173L;

	private LinkedList<Function> functions = new LinkedList<Function>();
	private String[] ignoreList = null;

	public UI() {
		super(LibraryOverrider.APPLICATION_NAME);

		this.setLayout(new BorderLayout());

		JPanel mainPanel = new JPanel();
		loadMainPanel(mainPanel);
		this.add(mainPanel, BorderLayout.CENTER);


		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setSize(480,720);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}

	private void loadMainPanel(JPanel mainPanel) {
		mainPanel.setLayout(new BorderLayout());
		// Configuration section
		JPanel topPanel = new JPanel();
		topPanel.setLayout(new GridLayout(2,2));
		JLabel externLabel = new JLabel("\"extern\" keyword");
		externLabel.setToolTipText("<html>The extern keyword can be replaced by a define in your header file:<br />type the define that defines the extern keyword here.</html>");
		topPanel.add(externLabel);
		fExternTF = new JTextField("extern");
		topPanel.add(fExternTF);

		JLabel ignoreListLabel = new JLabel("Ignore keyword list");
		ignoreListLabel.setToolTipText("<html>If the header contains some empty defines that may be ignored,<br />list them here. Separate them with comas.</html>");
		topPanel.add(ignoreListLabel);
		fIgnoreKeywordListTF = new JTextField("CL_API_CALL,CL_API_ENTRY,CL_EXT_PREFIX__VERSION_2_0_DEPRECATED,CL_EXT_PREFIX__VERSION_1_1_DEPRECATED,CL_EXT_PREFIX__VERSION_1_0_DEPRECATED");
		topPanel.add(fIgnoreKeywordListTF);

		mainPanel.add(topPanel, BorderLayout.NORTH);
		// Middle section
		fMainTA = new JTextArea(functions_txt);

		JScrollPane jsp = new JScrollPane(fMainTA);

		mainPanel.add(jsp, BorderLayout.CENTER);

		JPanel bottomPanel = new JPanel();
		bottomPanel.setLayout(new BorderLayout());
		JButton generateButton = new JButton("Generate");
		bottomPanel.add(generateButton, BorderLayout.WEST);
		generateButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent ae) {
				generateFiles();
			}
		});

		mainPanel.add(bottomPanel, BorderLayout.SOUTH);
	}

	protected void generateFiles() {
		ignoreList = fIgnoreKeywordListTF.getText().split(",");
		functions = new LinkedList<Function>();

		String content = fMainTA.getText();
		FunctionParser parser = new FunctionParser(content, fExternTF.getText());

		Pair<String, String> functionText = null;
		while((functionText = parser.getNextFunction()) != null) {
			processFunction(functionText);
		}
		String header = genHeader();
		String code = genCode();

		save(header, F_NAME + ".h");
		save(code, F_NAME + ".c");
		
		/*Enumeration<String> keys = Function.types.keys();
		String key = null;
		while(keys.hasMoreElements()) {
			key = keys.nextElement();
			Integer count = Function.types.get(key);
			System.out.println(key + " : " + count);
		}*/
		System.out.println("done");
	}

	private void save(String content, String filepath) {
		FileWriter fw = null;
		BufferedWriter bw = null;
		try {
			fw = new FileWriter(new File(filepath));
			bw = new BufferedWriter(fw);
			bw.write(content);
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(bw != null) {
				try {
					bw.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if(fw != null) {
				try {
					fw.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

	private String genCode() {
		
		String template = getRessourceAsString("clust.c.template");
		
		StringBuilder strbldr = new StringBuilder();

		for(Function fct : functions) {
			strbldr.append("cl_api_call_" + fct.getName() + " " + "reallib_" + fct.getName() + ";\n");
		}
		
		template = template.replaceAll("\\[\\[\\[reallibdefines\\]\\]\\]", strbldr.toString());
		
		strbldr = new StringBuilder();
		
		for(Function fct : functions) {
			strbldr.append("\treallib_" + fct.getName() + " = (cl_api_call_" + fct.getName() + ") dlSymFunction(libcl_ptr, \"" + fct.getName() + "\");\n");
		}
		
		template = template.replaceAll("\\[\\[\\[reallibdlsym\\]\\]\\]", strbldr.toString());

		strbldr = new StringBuilder();
		
		
		for(Function fct : functions) {
			strbldr.append(fct.getTracepointDeclaration() + "\n" + fct.getInstrumentedFunctionCode() + "\n\n");
		}

		template = template.replaceAll("\\[\\[\\[functions\\]\\]\\]", strbldr.toString());
		
		return template;
	}

	private String genHeader() {
		
		String template = getRessourceAsString("clust.h.template");

		StringBuilder strbldr = new StringBuilder();
		for(Function fct : functions) {
			strbldr.append(fct.getHeaderTypeDef() + "\n\n");
		}
		
		template = template.replaceAll("\\[\\[\\[functionprototypes\\]\\]\\]", strbldr.toString());

		return template;
	}
	
	private String getRessourceAsString(String ressourcePath) {
		InputStream is = UI.class.getResourceAsStream(ressourcePath);
		Reader r = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(r);
		StringBuilder stb = new StringBuilder();
		String line = null;
		try {
			while((line = br.readLine()) != null) {
				stb.append(line + "\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				r.close();
				is.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		return stb.toString();
	}

	private void processFunction(Pair<String, String> functionText) {
		try {
			functions.addLast(parseFunction(functionText));
		} catch (InvalidFunctionException e) {
			e.printStackTrace();
		}
	}

	private Function parseFunction(Pair<String, String> functionText) throws InvalidFunctionException {
		try {
			int paramStart = functionText.b.indexOf('(');
			int paramEnd = functionText.b.lastIndexOf(')');
			if(paramEnd < 0 || paramStart < 0) return null;

			String commentedParams = functionText.a.substring(paramStart + 1, paramEnd);
			String uncommentedParams = functionText.b.substring(paramStart + 1, paramEnd);
			String[] paramsStr = parseParameterString(uncommentedParams);
			int[] indexes = new int[paramsStr.length+1];
			if(indexes.length > 0) {
				indexes[0] = 0;
				indexes[indexes.length - 1] = uncommentedParams.length();
			}
			for(int i = 1; i < indexes.length - 1; i++) {
				indexes[i] = uncommentedParams.indexOf(',', indexes[i-1] + 1);
			}
			int currentIndex = 0;

			Function fct = new Function();

			
			// Getting the function's name
			int functionEnd = functionText.b.indexOf('(') - 1;
			while(Character.isWhitespace(functionEnd)) functionEnd--;
			int functionBegin = functionEnd - 1;
			if(functionEnd > 0) {
				while(!Character.isWhitespace(functionText.b.charAt(functionBegin))) functionBegin--;
			}
			if(functionBegin < 0) throw new InvalidFunctionException("Cannot locate the function name."); 
			String functionName = functionText.b.substring(functionBegin+1, functionEnd+1);
			fct.setName(functionName);

			// Getting the function's return type (we grab what ever is left before the name)
			String returnType = functionText.b.substring(0, functionBegin);
			
			int fctparend = functionText.b.lastIndexOf(')')+1;
			int fctpvend = functionText.b.lastIndexOf(';');
			String suffix = functionText.b.substring(fctparend, fctpvend);
			fct.setSufix(suffix);
			returnType = returnType.replace(fExternTF.getText().trim(), "");
			for(String ignore: ignoreList) {
				returnType = returnType.replaceAll(ignore, "");
			}
			fct.setReturnType(returnType.trim());
			
			for(String eachParam : paramsStr) {
				eachParam = eachParam.trim();
				while(eachParam.indexOf("  ") > 0) eachParam = eachParam.replaceAll("  ", " ");
				String type = "";
				String name = null;

				if(eachParam.startsWith("const ")) {
					type = "const ";
					eachParam = eachParam.substring(6);
				}

				// Find the name
				String[] parts = eachParam.split(" ");
				if(parts.length > 1) {
					for(int ix = 0; ix < parts.length - 1; ix++) {
						type += parts[ix] + " ";
					}
					if(parts[parts.length - 1].matches("(\\*)?[a-zA-Z_][a-zA-Z0-9_]*")) { // if the last part matches the definition of a variable name
						// The parts[length - 1] CAN be the name...further more validation to compute
						if(parts[parts.length-1].charAt(0) == '*') {
							if(parts[parts.length-1].length() > 1 && parts[parts.length-1].charAt(1) == '*') {
								type += "**";
								name = parts[parts.length-1].substring(2);
							} else {
								type += "*";
								name = parts[parts.length-1].substring(1);
							}
						} 
					} else { // The name is missing: everything left is the type
						type += parts[parts.length-1];
					}
				} else { // only the type can be left
					type += parts[0];
				}
				if(name == null) { // Look if there is a comment with the name or generate a new name
					String commentedParam = commentedParams.substring(indexes[currentIndex], indexes[currentIndex+1]);

					int s = commentedParam.indexOf("/*");
					int f = commentedParam.indexOf("*/");
					if(s >= 0 && f >= 0) { //There might be the name of the parameter in the commented section (type /* variable_name */) OpenCL's cl.h is built like this
						String insideComment = commentedParam.substring(s + 2, f).trim();
						if(!insideComment.contains(" ")) { // One word only: assume this is the param name
							name = insideComment;
						}
					}
				}

				Parameter param = new Parameter(type, name);

				fct.addParameter(param); // If there is no parameter name, the Function will automatically assign one.
				currentIndex++;
			}
			return fct;
		} catch(InvalidParameterException e) {
			e.printStackTrace();
			return null;
		}
	}

	private String[] parseParameterString(String uncommentedParams) throws InvalidParameterException {
		return new ParameterParser(uncommentedParams).getParams();
	}

	public static void main(String[] args) {
		
		InputStream is = UI.class.getResourceAsStream("cl.h.functions.txt");
		Reader r = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(r);
		StringBuilder stb = new StringBuilder();
		String line = null;
		try {
			while((line = br.readLine()) != null) {
				stb.append(line + "\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				br.close();
				r.close();
				is.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		functions_txt = stb.toString();
		
		new UI();
	}
}
