#pragma once
class CMyShape
{
public:
	CMyShape();
	virtual ~CMyShape();

	virtual void draw(CDC* pDC) = 0; // �̷� ����� �Լ��� �ʿ��ϴ�, �߻��Լ�(abstract function), �߻��Լ��� �ϳ��� ������ �߻�Ŭ������� ��, �߻�Ŭ������ ���� ���� �Ұ���
	virtual void setPt1(CPoint pt) = 0; // ������ �ٸ� Ŭ�������� ������ �������
	virtual void setPt2(CPoint pt) {}; // ���� �����൵ ��

	COLORREF m_color;
};

