import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class AdapterAction extends MouseAdapter { // �߻��Լ��� �ƴ� �� �Լ��� ���ǵǾ� ���� �ʿ��� �Լ��� ���� �������̵��ؼ� ���

	@Override
	public void mouseClicked(MouseEvent e) {
		KeyAndMousePanel p = (KeyAndMousePanel) e.getSource();

		p.l1.setLocation(e.getPoint());
	}

}

class KeyAndMousePanel extends JPanel implements ActionListener, MouseListener, MouseMotionListener, KeyListener {
	JButton b1;
	JButton b2;
	JLabel l1;

	KeyAndMousePanel() {
		this.setLayout(null);
		b1 = new JButton("button 1");
		b2 = new JButton("button 2");
		l1 = new JLabel("HELLO");

		add(b1);
		add(b2);
		add(l1);

		b1.setSize(90, 30);
		b1.setLocation(10, 10);

		b2.setSize(90, 30);
		b2.setLocation(100, 10);

		l1.setSize(90, 30);
		l1.setLocation(200, 10);

//		b1.addActionListener(new ActionListener() {
//			public void actionPerformed(ActionEvent arg0) {
//				l1.setText("WORLD");
//			}
//		});
//		
//		b2.addActionListener(new ActionListener() {
//			public void actionPerformed(ActionEvent arg0) {
//				l1.setText("HELLO");
//			}
//		}); // ���� Ŭ����

		b1.addActionListener(this);
		b2.addActionListener(this); // �г��� �׼Ǹ����ʸ� ����
		// this.addMouseListener(this);
		this.addMouseListener(new AdapterAction());
		this.addMouseMotionListener(this);

		this.setFocusable(true);
		this.requestFocus();
		this.addKeyListener(this);
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		if (b1 == arg0.getSource()) { // � ��ư�� ���ȴ��� Ȯ���� ���� ����
			l1.setText("WORLD");
		}

		if (b2 == arg0.getSource()) {
			l1.setText("HELLO");
		}

	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
		l1.setLocation(arg0.getPoint());

		if (arg0.getClickCount() == 2) { // ���ڸ����� ��� ����Ŭ���ϸ� Count�� ������

		}

		if (arg0.getClickCount() == 2 && arg0.getButton() == MouseEvent.BUTTON1) { // BUTTON1 ��Ŭ��, 2 ���Ŭ��, 3 ��Ŭ��

		}
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {

	}

	@Override
	public void mouseExited(MouseEvent arg0) {
	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		this.setBackground(Color.RED);
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		this.setBackground(Color.WHITE);
	}

	@Override
	public void mouseDragged(MouseEvent arg0) {
		l1.setLocation(arg0.getX(), arg0.getY());

	}

	@Override
	public void mouseMoved(MouseEvent arg0) {
		l1.setText("X : " + arg0.getX() + ", Y : " + arg0.getY());

	}

	@Override
	public void keyPressed(KeyEvent arg0) { // � Ű�� �����°� r == R == �� == �� ���� ���� Ű
		//this.setBackground(Color.BLUE);
		if(arg0.getKeyCode() == KeyEvent.VK_LEFT)
		{
			java.awt.Point p = l1.getLocation();
			p.x -= 10;
			l1.setLocation(p);
		}
		
		if(arg0.getKeyCode() == KeyEvent.VK_RIGHT)
		{
			java.awt.Point p = l1.getLocation();
			p.x += 10;
			l1.setLocation(p);
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		this.setBackground(Color.WHITE);
	}

	@Override
	public void keyTyped(KeyEvent arg0) { // r, R, ��, �� �߿� � ������� ����ؾ��ϴ°�
		
	}
}

public class KeyAndMouse extends JFrame {

	KeyAndMouse() {
		setTitle("Key and Mouse");
		setSize(500, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		KeyAndMousePanel p = new KeyAndMousePanel();
		add(p);

		setVisible(true);
	}

	public static void main(String[] args) {
		new KeyAndMouse();
	}

}
