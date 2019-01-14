#include <iostream>
#include <cstring>
using namespace std;

class Book
{
	char *title;
	int price;
public:
	Book(const char* title, int price);
	Book(Book &a);
	~Book();
	void set(char* title, int price);
	void show() { cout << title << " " << price << "��" << endl; }
};

Book::Book(const char * title, int price)
{
	int size = strlen(title); // ���� ���� ���ϰ�
	this->title = new char[size+1]; // �� ũ��+1 ��ŭ �����Ҵ��մϴ�.
	strcpy(this->title, title); // ���ڿ��� �����մϴ�.
	this->price = price; // ������ �����մϴ�. 
}

void Book::set(char*title, int price)
{
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book()
{
	delete[] title;
}

Book::Book(Book &a)
{
	int size = strlen(a.title); 
	this->title = new char[size+1]; 
	strcpy(this->title, a.title);
	this->price = price;
} // ���� ���縦 ���� ���Ӱ� �����Ҵ� �� �����͸� �����մϴ�.

int main()
{
	Book cpp("��ǰ C++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�",12000);
	cpp.show();
	java.show();

	return 0;
}