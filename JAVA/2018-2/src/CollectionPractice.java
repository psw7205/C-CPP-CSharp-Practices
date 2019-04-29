import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Vector;
// array ��ü ���������� ���� 
// �����＼�� ����
// �߰��� ���� �� ��ĭ�� �� �ڷ� �̷�� ����, ���� �� ���� ��ĭ �� ������ ���

public class CollectionPractice {

	public static void func(String[] a) {
		for (String ar : a)
			System.out.println(ar);
	}

	public static void main(String[] args) {

		Vector<Integer> v = new Vector<>();

		v.add(10); // boxing ��... int�� Integer�� �ٲ�......
		v.add(20);
		v.add(40);
		v.set(2, 30); // 2��° �ε��� ���� 30����
		v.add(1, 15); // 1��° �ε��� �տ� 15�߰�
		v.remove(0); // 0��° �ε��� �� ����

		for (int i = 0; i < v.size(); i++)
			System.out.println(v.get(i));

		for (Integer e : v)
			System.out.println(e);

		ArrayList<String> v2 = new ArrayList<>();

		v2.add("�ڻ��");
		v2.add("����");
		v2.add("���б�");
		v2.add("����Ʈ�����а�");
		v2.remove("����Ʈ�����а�"); // ���ϴ� �����͵� ���� ����

		for (String str : v2)
			System.out.println(str);

		System.out.println(v2.indexOf("���б�")); // ���� ���ڿ��� ã�� �ε��� ����

		String[] arr = new String[v2.size()];

		v2.toArray(arr); // String �迭�� ��ȯ
		func(arr);

		LinkedList<String> v3 = new LinkedList<>();

		v3.add("�ڻ��");
		v3.add("����");
		v3.add("���б�");
		v3.add("����Ʈ�����а�");
		
		for (String str : v3) // �б����� foreach���� ��� ������
			System.out.println(str);

		for (int i = 0; i < v3.size(); i++)
			System.out.println(v3.get(i)); //��ũ�帮��Ʈ���� �Ϲ����� for��ó�� �ۼ��ϸ� �ȵ�, �� ������ ���ڱ��� �����ϴµ� O(n^2)
		// ���������� ������
		
		Iterator<String> it = v3.iterator(); // iterator�� ���
		
		while(it.hasNext() == true) // ���� �����Ͱ� �ִ� ����
		{
			String e = it.next(); // ���� �����ͷ� �̵��ϰ� e�� ���� 
			System.out.println("iterator : " + e); // ���
		}
		
		
		LinkedList<Integer> v4 = new LinkedList<>();
		
		v4.add(0);
		v4.add(1);
		v4.add(2);
		v4.add(3);
		
		for(int e : v4)
			System.out.println(e);
		
		Iterator<Integer> it2 = v4.iterator(); // ó���� ������� ����Ŵ
		
		System.out.println("==" + it2.next()); // �������� it2 �̵�
		it2.remove();
		
		for(int e : v4)
			System.out.println(e);
		
////////////////////////////////////////////////////////////////
		//Collections�� static �Լ��� �˰��� ��� ����

		Collections.sort(v3); // ����
		for (String str : v3)
			System.out.println(str);
		
		Collections.reverse(v3); // �������� ����
		for (String str : v3)
			System.out.println(str);
	}
}
