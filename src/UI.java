import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;


public class UI extends JFrame {

	JTextArea fMainTA; 
	JTextField fExternTF, fIgnoreKeywordListTF;
	/**
	 * 
	 */
	private static final long serialVersionUID = -7316827103620049173L;

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
	}
	
	public static void main(String[] args) {
		new UI();
	}
}
