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
		int paramStart = functionText.b.indexOf('(');
		int paramEnd = functionText.b.indexOf(')');
		if(paramEnd < 0 || paramStart < 0) return null;
		
		String[] paramsStr = functionText.b.substring(paramStart + 1, paramEnd).split(",");
		
		Function fct = new Function();
		for(String eachParam : paramsStr) {
			eachParam = eachParam.trim();
			while(eachParam.indexOf("  ") > 0) eachParam = eachParam.replaceAll("  ", " ");
			String[] parts = eachParam.split(" ");
			
			int partsCount = parts.length;
			Parameter param = null;
			switch(partsCount) {
			case 1:
				param = new Parameter(parts[0]);
				break;
			case 2:
				if(parts[1].startsWith("*")) {
					param = new Parameter(parts[0] + "*", parts[1].substring(1));
				} else {
					param = new Parameter(parts[0], parts[1]);
				}
				break;
			case 3:
				if(parts[1].equals("*")) {
					param = new Parameter(parts[0] + "*", parts[2]);
				} else {
					System.err.println("Unusual format of a parameter.");
				}
				break;
			default:
				System.err.println("Unusual number of parts for a parameter.");
				return null;
			}

			fct.addParameter(param);
		}
		return null;
	}

	public static void main(String[] args) {
		new UI();
	}
}
