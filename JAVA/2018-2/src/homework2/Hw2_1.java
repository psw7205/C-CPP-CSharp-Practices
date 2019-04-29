package homework2;

abstract class PairMap {
	protected String keyArray[]; // key�� �����ϴ� �迭
	protected String valueArray[]; // value�� �����ϴ� �迭

	abstract String get(String key); // key���� ���� value ����, ������ null

	abstract void put(String key, String value); // key,value ������ ����, key�� �ߺ��Ǹ� value����

	abstract String delete(String key); // key�� ���� ������ ����, ������ value ����

	abstract int length(); // ����� �������� ���� ����
}

class Dictionary extends PairMap {
	int cnt;

	Dictionary(int in) {
		this.keyArray = new String[in];
		this.valueArray = new String[in];
		this.cnt = 0;
	}

	@Override
	String get(String key) {
		for (int i = 0; i < cnt; i++) {
			if (keyArray[i].equals(key)) {
				return valueArray[i];
			}
		}
		return null;
	}

	@Override
	void put(String key, String value) {

		for (int i = 0; i < cnt; i++) {
			if (keyArray[i].equals(key)) {
				valueArray[i] = value;
				return;
			}
		}

		keyArray[cnt] = key;
		valueArray[cnt] = value;
		cnt++;
		return;
	}

	@Override
	String delete(String key) {
		for (int i = 0; i < cnt; i++) {
			if (keyArray[i].equals(key)) {
				String str = valueArray[i];
				for (int j = i; j < keyArray.length - 1; j++) {
					keyArray[j] = keyArray[j + 1];
					valueArray[j] = valueArray[j + 1];
				}
				keyArray[cnt] = null;
				valueArray[cnt] = null;
				cnt--;
				return str;
			}
		}
		return null;
	}

	@Override
	int length() {
		return this.cnt;
	}

}

public class Hw2_1 {

	public static void main(String[] args) {
		Dictionary dic = new Dictionary(10);
		dic.put("Ȳ����", "�ڹ�");
		dic.put("���繮", "���̽�");
		dic.put("���繮", "C++");
		System.out.println("���繮�� ���� " + dic.get("���繮"));
		System.out.println("Ȳ������ ���� " + dic.get("Ȳ����"));
		dic.delete("Ȳ����");
		System.out.println("Ȳ������ ���� " + dic.get("Ȳ����"));

	}

}
