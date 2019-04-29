import java.awt.BorderLayout;
import java.awt.Color;

import javax.swing.*;

public class HelloSwing extends JFrame {
// multi thread
// �Ϲ������� ���α׷� �� ��ü�� ������
	HelloSwing(){
		setSize(300, 300);
		setTitle("Hello, Swing");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

//		JButton button = new JButton();
//		add(button);
//		button.setText("My Button");
		
		// �г��� �⺻������ flowLayout, �������� borderLayout
		// ��ġ�����ڿ��� ����
		JPanel panel = new JPanel(); // ���۳�Ʈ���� ���ʿ��� ����������, �ڸ��� �����ϸ� �Ʒ��� �߰���, ���� ����
		panel.add(new JButton("panel Button1"));
		panel.add(new JButton("panel Button2"));
		panel.add(new JLabel("panel Label"));
		panel.setBackground(Color.BLUE);
		
		add(panel,  BorderLayout.CENTER); // ���۳�Ʈ���� �߰��� �г��� ����� �߰�
		//add(new JButton("My Button 1")); // �̷������� �߰� ����
		add(new JButton("My Button 2"), BorderLayout.NORTH); // ���ʿ� ��ư �߰�
		add(new JButton("My Button 3"), BorderLayout.SOUTH); // ���̾ƿ����� ��ȹ�� ������ �ְ� ���۳�Ʈ�� �ٿ� ǥ��
		add(new JButton("My Button 4"), BorderLayout.EAST);
		add(new JButton("My Button 5"), BorderLayout.WEST); 
		
		panel.setLayout(null);
		for(int i=0; i<5; i++)
		{
			JButton but = new JButton("Button "+i);
			but.setLocation(100*i, 100*i);
			but.setSize(100,50);
			add(but);
		}
		
		add(panel, BorderLayout.CENTER);
		
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new HelloSwing();

	}

}
