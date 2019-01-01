#include<stdio.h> 
#include<stdlib.h> 
#pragma warning(disable:4996)

typedef struct treeNode 
{
	int data;				
	struct treeNode* left;	
	struct treeNode* right;	
} treeNode;

// ���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� �����Դϴ�.
// ���س�� �� �Է¹ް� root��忡�� ���س����� �̵��ϱ� ���� ����߽��ϴ�.
treeNode* searchtreeNode(treeNode* root, char x) 
{
	treeNode* p = root; 

	while (p != NULL) {

		if (x < p->data) 
			p = p->left; // ���ϴ� ����� ���� ���� ����� ������ ������ �����ڽĳ��� �̵��մϴ�.
		else if (x == p->data)
			return p; // ���ϴ� ���س����� �̵������� ���س�带 �����մϴ�.
		else 
			p = p->right; // �ƴϸ� ������ �ڽĳ��� �̵��մϴ�.
	}

	printf("ã�� ��尡 �����ϴ�!\n");
	return root; // ��带 ��ã������ �׳� ��Ʈ��带 �ٽ� �����մϴ�.
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� �����Դϴ�.
treeNode* insertNode(treeNode *p, int x) 
{
	treeNode *newNode;

	if (p == NULL) // p�� ����Ű�� ��忡�� ������ ��ġ���� ���������� 
	{
		newNode = (treeNode*)malloc(sizeof(treeNode)); // ���ο� ��带 �����
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode; // ������ �� ��带 �����մϴ�.
	}
	else if (x < p->data)
		p->left = insertNode(p->left, x); // ������ ���� ������ �����ͺ��� ������ �����ڽ�����
	else if (x > p->data)
		p->right = insertNode(p->right, x); // ũ�� ������ �ڽ����� ���ȣ���ϸ� �������ϴ�.
	else
		printf("�̹� ���� Ű�� �ֽ��ϴ�!\n");

	return p; // ����尡 ���ϵ��� �ʾҴٸ� �ߺ��� ���� �ִ� ���̰� 
	//����Ž��Ʈ������ ���� ���� �ߺ��� �� ������ �׳� �����մϴ�.
}

treeNode* maxNode(treeNode *p) // ��������Ʈ�� �� ���� ū ��带 ã�� �Լ��Դϴ�.
{
	treeNode* tmp = p; // �տ��� Ž���� tmp �������Դϴ�.
	treeNode* q = NULL; // ������ ���� ū ��带 ������ �������Դϴ�.

	if (tmp->left == NULL) // ���س�� left�� NULL�̸� ��������Ʈ���� �������� �ʴ� ���̰�
	{
		printf("���س�� ��������Ʈ���� �������� �ʽ��ϴ�.\n");
		return tmp; // ���س�带 �����մϴ�.
	}

	tmp = tmp->left; // ������ ���ϵ��� �ʾ����� ��������Ʈ���� �̵� ��

	while (tmp != NULL) // tmp�� NULL�� �ƴ� ������
	{
		q = tmp; // q�� tmp�� �����ϰ�
		tmp = tmp->right; // tmp�� ������ �ڽ����� �̵���ŵ�ϴ�.
	}

	// tmp�� NULL�� �Ǿ��� ���̻� ������ �ڽ��� ������ 
	return q; //�� ��尡 �ִ� ����̹Ƿ� q�� �����մϴ�.
}

treeNode* minNode(treeNode *p) // ��������Ʈ�� �� ���� ���� ��带 ã�� �Լ��Դϴ�.
{// maxNode�Լ��� ����� ������ ���� ��������Ʈ���� �̵� �� ������ ���� �ڽı��� �̵��� �ּ� ��带 ã�ҽ��ϴ�.
	treeNode* tmp = p;
	treeNode* q = NULL;

	if (tmp->right == NULL)
	{
		printf("���س�� ��������Ʈ���� �������� �ʽ��ϴ�.\n");
		return tmp;
	}

	tmp = tmp->right;

	while (tmp != NULL)
	{
		q = tmp;
		tmp = tmp->left;
	}

	return q;
}

int main()
{
	treeNode* root = NULL; // ��Ʈ����Դϴ�. 
	int  leftMax, rightMin, n; // ��������Ʈ�� �ִ�, ��������Ʈ�� �ּ�, ���س���� ���� ������ �������Դϴ�. 

	root = insertNode(root, 8); 
	insertNode(root, 3);
	insertNode(root, 10);
	insertNode(root, 2);
	insertNode(root, 5);
	insertNode(root, 14);
	insertNode(root, 4);
	insertNode(root, 11);
	insertNode(root, 16); // insertNode�Լ��� �̿��� �������� �־��� Ʈ���� ��������ϴ�.

	printf("���� ��带 �Է��ϼ��� : ");

	scanf("%d", &n); // ���س���� ���� �Է¹ް�

	root = searchtreeNode(root, n); // ���س�带 ��Ʈ���� �ٽ� �����մϴ�.

	leftMax = maxNode(root)->data; // maxNode�Լ���
	rightMin = minNode(root)->data; // minNode�Լ��� �̿��� ���� ����޽��ϴ�.
	
	printf("���س����  ��������Ʈ������  ���� ū ���� %d, ��������Ʈ������ ���� ���� ���� %d �Դϴ�\n", leftMax, rightMin);

	return 0;
}