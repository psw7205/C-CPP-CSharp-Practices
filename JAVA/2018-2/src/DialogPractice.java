import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

class StringDialog extends JDialog {
	JTextField text;
	StringDialog(JFrame frame, String title, boolean modal) {
		super(frame, title, modal);
		this.setLayout(new FlowLayout());
		
		JDialog dlg = this;
		
		text = new JTextField(20);
		text.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
		
				dlg.setVisible(false);
			}
			
		});
		add(text);

	}
}

class DialogPanel extends JPanel implements ActionListener {
	JLabel label;
	JFrame frame;
	DialogPanel() {
		label = new JLabel("label");
		JButton btn = new JButton("Push");

		btn.addActionListener(this);
		
		add(label);
		add(btn);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		// �̹� �ϼ��Ǿ� �ִ� ���̾�α׵�
		JFileChooser chooser = new JFileChooser();
		if(chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
		{
			label.setText(chooser.getSelectedFile().getPath());
		}
		
		
		String str = JOptionPane.showInputDialog("���ڿ��� �Է��ϼ���");
		if(str != null)
			label.setText(str);
		
		int result = JOptionPane.showConfirmDialog(this,  "Ȯ���ϼ���");
		switch(result)
		{
		case JOptionPane.YES_OPTION : 
			label.setText("��");
			break;
		case JOptionPane.NO_OPTION : 
			label.setText("�ƴϿ�");
			break;
		case JOptionPane.CANCEL_OPTION : 
			label.setText("���");
			break;
		}
		
		JOptionPane.showMessageDialog(this, "�޼������");
		
		StringDialog dlg = new StringDialog(frame, "���", true);
		dlg.setSize(300, 100);
		
		dlg.text.setText(label.getText());
		dlg.setVisible(true);
		
		label.setText(dlg.text.getText());

	}
}

public class DialogPractice extends JFrame {

	DialogPractice() {
		this.setSize(300, 300);
		this.setTitle("Dialog Practice");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);

		DialogPanel p = new DialogPanel();
		p.frame = this;
		this.add(p);

		this.setVisible(true);
	}

	public static void main(String[] args) {
		new DialogPractice();

	}

}
