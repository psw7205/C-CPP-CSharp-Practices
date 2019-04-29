import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class MyLabel extends JLabel implements ActionListener {

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// �̺�Ʈ�� �߻��ϸ� �� �Լ��� ȣ���
		JButton b = (JButton) arg0.getSource();
		String str = b.getText();

		if (str.equals("button"))
			b.setText("Click");
		else
			b.setText("button");

		setText(" l2 : �ȳ��ϼ���");
	}
}

class MyAction implements ActionListener {
	JLabel l;
	JPanel p;

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// �̺�Ʈ�� �߻��ϸ� �� �Լ��� ȣ���
		JButton b = (JButton) arg0.getSource();
		String str = b.getText();

		if (str.equals("button"))
			b.setText("Click");
		else
			b.setText("button");

		l.setText("l : �ȳ��ϼ���");
		p.setBackground(java.awt.Color.YELLOW);

	}

}

class EventHandlingPanel extends JPanel implements ActionListener { // �������� �������� �� ���� ��ư�� �гο��� ����
	JButton b;
	JLabel l;
	JButton b2;

	EventHandlingPanel() {

		b = new JButton("button");
		add(b);

		b2 = new JButton("button2");
		add(b2);

		MyAction act = new MyAction();

		l = new JLabel("l : hello world");
		MyLabel l2 = new MyLabel();

		l2.setText(" l2 : hewllo world");

		act.l = l;
		act.p = this;
		// b.addActionListener(l2); // �� ��ư�� �׼��� ó���� �� �ִ� �����ʸ� ���
		// b.addActionListener(act);

		JPanel p = this;
		// ������ �� �׼Ǹ����ʴ� �� Ŭ���������� ����ϴ� �׳� anonymous class�� ���
		b.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent arg0) {
				String str = b.getText();

				if (str.equals("button"))
					b.setText("Click");
				else
					b.setText("button");

				l.setText("anonymous class���");
				l2.setText("~~~");

				p.setBackground(Color.GRAY);

			}

		});

		b2.addActionListener(this);
		b2.addMouseListener(new MouseListener() {

			@Override
			public void mouseClicked(MouseEvent arg0) {

			}

			@Override
			public void mouseEntered(MouseEvent arg0) {
				b2.setBackground(Color.RED);
			}

			@Override
			public void mouseExited(MouseEvent arg0) {
				b2.setBackground(Color.WHITE);
			}

			@Override
			public void mousePressed(MouseEvent arg0) {

			}

			@Override
			public void mouseReleased(MouseEvent arg0) {

			}

		});

		l2.addMouseListener(new MouseListener() {

			@Override
			public void mouseClicked(MouseEvent arg0) {
				l2.setText("���콺Ŭ������ �ؽ�Ʈ ����");
			}

			@Override
			public void mouseEntered(MouseEvent arg0) {

			}

			@Override
			public void mouseExited(MouseEvent arg0) {

			}

			@Override
			public void mousePressed(MouseEvent arg0) {

			}

			@Override
			public void mouseReleased(MouseEvent arg0) {

			}

		});

		add(l);
		add(l2);

	}

	@Override
	public void actionPerformed(ActionEvent arg0) {

		// �� ��� ��ư�� ���� �ϱ� ���ؼ� �Լ� �ӿ��� ���� ���ǹ��� �ʿ���
		if (arg0.getSource() == b) {
			String str = b.getText();

			if (str.equals("button"))
				b.setText("Click");
			else
				b.setText("button");

			l.setText("panel�� �������̽��� �߰��� ����");

			setBackground(java.awt.Color.PINK);
		}

		if (arg0.getSource() == b2) {
			String str = b.getText();

			if (str.equals("button"))
				b.setText("Click");
			else
				b.setText("button");

			l.setText("panel�� �������̽��� �߰��� ����");

			setBackground(Color.PINK);
		}

	}

}

public class EventEandlingPractice extends JFrame {

	EventEandlingPractice() {
		// �⺻ ���� : Ÿ��Ʋ, ������, x ��ư ���� �� ����, ȭ�� ���
		this.setTitle("Event Handling Practice");
		this.setSize(400, 300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		EventHandlingPanel p = new EventHandlingPanel();

		add(p);

		this.setVisible(true);
	}

	public static void main(String[] args) {

		new EventEandlingPractice();
	}

}
