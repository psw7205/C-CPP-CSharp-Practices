import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;

class GraphicsPanel extends JPanel implements MouseListener, MouseMotionListener {

	ArrayList<Point> sp;
	ArrayList<Point> ep; // ������ ���� �׸��� ���� ����Ʈ ����Ʈ

	int sx, sy, ex, ey;
	boolean lButton = false;

	GraphicsPanel() {
		this.addMouseListener(this); // ���콺�����ʸ� ���
		this.addMouseMotionListener(this);
		sp = new ArrayList<Point>();
		ep = new ArrayList<Point>();
	}

	// �ʿ��Ҷ����� �ڵ����� ȣ��
	@Override
	protected void paintComponent(Graphics g) {

		super.paintComponent(g); // �θ� Ŭ������ �Լ��� ���� �θ��� ���� (�θ� Ŭ������ �Լ��� �ٲ�ġ�� ������ ������ ������ ���� �� ����)
		
		// draw�Լ��� ����, fill�� ���� ä���� �׸�
		int w = this.getWidth();
		int h = this.getHeight(); // ȭ�� ũ�⸦ ��� ����

		// int[] x = { 150, 100, 150, 200};
		int[] x = { w / 2, 0, w / 2, w };
		// int[] y = { 50, 100, 150, 100};
		int[] y = { 0, h / 2, h, h / 2 };
		g.setColor(Color.RED);
		g.fillPolygon(x, y, 4); // ȭ���� ������ ������

		Color c = new Color(255, 0, 0); // RGB���� �������� �Ķ���ͷ� ����
		g.setColor(c); // �׸��� ���� ���� ����
		g.drawRect(100, 100, 300, 200); // 100, 100�� ���������� ���η� 300, ���η� 200 ũ���� �簢��

		g.setColor(Color.CYAN); // RED, GREEN, BLUE, BLACK, WHITE, GRAY, MAGENTA, CYAN, YELLOW ... �̹� ���������
								// �������ִ� ����
		g.drawLine(100, 100, 300, 200); // �������� ����

		g.setColor(Color.BLACK);
		g.drawOval(100, 100, 300, 200); // �� �簢���� ä��� ��

		g.setColor(Color.MAGENTA);
		g.drawRoundRect(100, 100, 300, 200, 50, 50); // �簢���ε� �𼭸��� �ձ� �簢��

		g.setColor(Color.ORANGE);
		g.setFont(new Font("�ü�ü", Font.ITALIC, 30));// ��Ʈ����
		g.drawString("�������б�", 100, 100); // ������ �ٷ� ���� ��Ÿ��
		g.setColor(Color.WHITE);
		g.drawString("�������б�", 98, 98);

		g.setColor(Color.BLACK);
		//g.drawLine(sx, sy, ex, ey);
		

		for(int i = 0; i < sp.size(); i++)
		{
			Point s = sp.get(i);
			Point e = ep.get(i);
			g.drawLine(s.x, s.y, e.x, e.y);
		}
		
	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
		// TODO Auto-generated method stub

	}

	@Override
	public void mouseEntered(MouseEvent arg0) {

	}

	@Override
	public void mouseExited(MouseEvent arg0) {

	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		if (arg0.getButton() == MouseEvent.BUTTON1) {
			//sx = arg0.getX();
			//sy = arg0.getY();
			
			Point p1 = new Point(arg0.getX(), arg0.getY());
			Point p2 = new Point(arg0.getX(), arg0.getY());
			
			sp.add(p1);
			ep.add(p2);
			lButton = true;
		}
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		if (arg0.getButton() == MouseEvent.BUTTON1) {
			//ex = arg0.getX();
			//ey = arg0.getY();
			
			Point p = ep.get(ep.size()-1);
			p.x = arg0.getX();
			p.y = arg0.getY(); // �ڹٴ� ���۷����̱� ������ �����͸� �ٲ���� 
			
			lButton = false;
			this.repaint(); // �ٽ� �׷����Ѵٰ� ��û
		}
	}

	@Override
	public void mouseDragged(MouseEvent arg0) {
		if (lButton == true) { // flag������ �� ��ư Ȯ��
			//ex = arg0.getX();
			//ey = arg0.getY();
			
			Point p = ep.get(ep.size()-1);
			p.x = arg0.getX();
			p.y = arg0.getY();
			this.repaint(); // �ٽ� �׷����Ѵٰ� ��û
		}
	}

	@Override
	public void mouseMoved(MouseEvent arg0) {

	}
}

// �׸��� �ڿ��� ���� �׷��� ������ -> �г� ��
// �����찡 �����ӿ��� �׸���� ���, �������� �׸��� �����ӿ� ���Ե� ������Ʈ�� �ٽ� �׸���� ���
public class GraphicsPractice extends JFrame {
	GraphicsPractice() {
		setTitle("Graphics Practice");
		setSize(500, 500);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		GraphicsPanel p = new GraphicsPanel();
		add(p);

		setVisible(true);
	}

	public static void main(String[] args) {
		new GraphicsPractice();
	}

}
