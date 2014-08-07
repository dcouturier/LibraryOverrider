import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.rmi.UnexpectedException;
import java.util.LinkedList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import element.Function;
import element.Parameter;
import lex.FileCleaner;
import lex.FunctionParser;
import lex.InvalidParameterException;
import lex.ParameterParser;
import utils.Functions;
import utils.Pair;


public class UI extends JFrame {

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
		fIgnoreKeywordListTF = new JTextField();
		topPanel.add(fIgnoreKeywordListTF);

		mainPanel.add(topPanel, BorderLayout.NORTH);
		// Middle section
		fMainTA = new JTextArea();

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

		String content = fMainTA.getText();
		FunctionParser parser = new FunctionParser(content, fExternTF.getText());

		Pair<String, String> functionText = null;
		while((functionText = parser.getNextFunction()) != null) {
			processFunction(functionText);
		}
	}

	private void processFunction(Pair<String, String> functionText) {
		functions.addLast(parseFunction(functionText));
	}

	private Function parseFunction(Pair<String, String> functionText) {
		try {
			int paramStart = functionText.b.indexOf('(');
			int paramEnd = functionText.b.indexOf(')');
			if(paramEnd < 0 || paramStart < 0) return null;

			String commentedParams = functionText.a.substring(paramStart + 1, paramEnd);
			String uncommentedParams = functionText.b.substring(paramStart + 1, paramEnd);
			String[] paramsStr = parseParameterString(uncommentedParams);
			int[] indexes = new int[paramsStr.length+1];
			if(indexes.length > 0) {
				indexes[0] = 0;
				indexes[indexes.length - 1] = uncommentedParams.length() - 1;
			}
			for(int i = 1; i < indexes.length - 1; i++) {
				indexes[i] = uncommentedParams.indexOf(',', indexes[i-1] + 1);
			}
			int currentIndex = 0;

			Function fct = new Function();
			for(String eachParam : paramsStr) {
				eachParam = eachParam.trim();
				while(eachParam.indexOf("  ") > 0) eachParam = eachParam.replaceAll("  ", " ");
				String type = "";
				String name = "";
				Parameter param = null;
				
				if(eachParam.startsWith("const ")) {
					type = "const ";
					eachParam = eachParam.substring(6);
				}
				
				// Find the name
				String[] parts = eachParam.split(" ");
				if(parts.length > 1) {
					if(parts[parts.length - 1].matches("(\\*)?[a-zA-Z_][a-zA-Z0-9_]*")) { // if the last part matches the definition of a variable name
						// The parts[length - 1] CAN be the name...further more validation to compute
						if(parts.length == 2) { // check if the second item starts with a * (then we have "type *name")
							type += parts[0];
							if(parts[1].charAt(0) == '*') {
								if(parts[1].length() > 1 && parts[1].charAt(1) == '*') {
									type += "**";
									name = parts[1].substring(2);
								} else {
									type += "*";
									name = parts[1].substring(1);
								}
							}
						} //TODO else...
					} else { // The name is missing: everything left is the type
						type += eachParam;
					}
				} else { // only the type can be left
					type += parts[0];
				}
								
				/*
				String[] parts = eachParam.split(" ");

				int partsCount = parts.length;
				switch(partsCount) {
				case 1:
					param = new Parameter(type + parts[0]);
					break;
				case 2:
					if(parts[1].startsWith("*")) {
						param = new Parameter(type + parts[0] + "*", parts[1].substring(1));
					} else {
						param = new Parameter(type + parts[0], parts[1]);
					}
					break;
				case 3:
					if(parts[1].matches("")) {
						param = new Parameter(type + parts[0] + "*", parts[2]);
					} else {
						System.err.println("Unusual format of a parameter.");
					}
					break;
				default:
					if(eachParam.contains("(")) { // Could be a complex parameter
						if(parts[])
					}
					return null;
				}*/

				if(param.getName() == null) { // Look if there is a comment with the name or generate a new name
					String commentedParam = commentedParams.substring(indexes[currentIndex], indexes[currentIndex+1]);

					int s = commentedParam.indexOf("/*");
					int f = commentedParam.indexOf("*/");
					if(s >= 0 && f >= 0) { //There might be the name of the parameter in the commented section (type /* variable_name */) OpenCL's cl.h is built like this
						String insideComment = commentedParam.substring(s + 2, f).trim();
						if(!insideComment.contains(" ")) { // One word only: assume this is the param name
							param.setName(insideComment);
						}
					}
				}

				fct.addParameter(param); // If there is no parameter name, the Function will automatically assign one.
				currentIndex++;
			}
			return fct;
		} catch(InvalidParameterException e) {
			return null;
		}
	}

	private String[] parseParameterString(String uncommentedParams) throws InvalidParameterException {
		return new ParameterParser(uncommentedParams).getParams();
	}

	public static void main(String[] args) {
		new UI();
	}
}
