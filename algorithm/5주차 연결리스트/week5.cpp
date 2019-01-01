#include <stdio.h>
#include <malloc.h>


#pragma warning(disable:4996)

typedef struct node_{ // ���߿��Ḯ��Ʈ ��� ����
	char alpha; // ���Ҵ� ���ĺ� 1��
	struct node_ *before; // ���� ��忡 ���� ������
	struct node_ *next; // ���� ��忡 ���� ������
}; 



node_* getNode() { // ���ο� ��带 �����Ҵ��Ͽ� ��ȯ
	node_ *new_node;
	new_node = (node_*)malloc(sizeof(node_));
	return new_node;
}

void initList(node_ **header, node_ **tailer) { // ���ʿ� ������� ������带 ����
	*header = getNode(); // �����Ҵ�
	*tailer = getNode();
	(*header)->next = *tailer; // ���ʿ� �������� ������ ��������̴�.
	(*tailer)->before = *header; // ���ʿ� ��������� ������ �������̴�.
	return;
}





node_* insertAfter(node_ *p, char c) { // ���� ����� ������ c�� ���ĺ��� ���� ���ο� ��带 ����
	node_ *temp;
	temp = getNode(); // ���ο� ��带 �����Ҵ�
	temp->alpha = c; // ���ο� ����� ���ĺ��� c
	// ���ο� ��带 �����Ҷ��� ������ ������ ������ �����ؾ��Ѵ�.
	// (���ο� ����� �����͸� ���� ����, ���� ����� �����͸� ����)
	temp->before = p; // ���ο� ����� �����͸� ���� ����
	temp->next = p->next;
	p->next->before = temp; // ������ ����� �����͸� ����
	p->next = temp;
	return temp;
}



char removeNode(node_ *p) { // �ش��ϴ� ��带 �����Ѵ�.
	char c = p->alpha;
	p->before->next = p->next;
	p->next->before = p->before;
	free(p); // �����Ҵ� ������ ���ش�.
	return c;
}


node_* getnNode(node_ *header, node_ *tailer, int position) { // n��° ��带 ��ȯ�ϴ� �Լ�.
	node_ *temp = header; // node temp�� ����������, ��� header�� �״�� ����ص� �����ϴ�.
	for (int i = 0; i < position; i++) { // n��° ���� �ٴٸ������� �ݺ��Ѵ�.
		temp = temp->next;
		if (temp == tailer) { // ���� position�� �ٴٸ������� ����Ʈ�� ���������.
			printf("invalid position\n");
			return NULL;
		}
	}
	return temp;
}


// n��°(���, ���� ��带 ������)�� ���ο� ��带 �߰��ϴ� �Լ�.
void add(node_ *header, node_ *tailer, int position, char item) {
	node_ *temp;
	temp = getnNode(header, tailer, position-1); // n-1��° �ڿ� ���ο� ��带 �߰��ؾ� �ϹǷ� n-1��° ��带 �����´�.
	if(temp!=NULL)
		insertAfter(temp, item); // n-1��° �ڿ� ���ο� ��带 �߰�.

}

// n��° ��带 �����ϴ� �Լ�.
void _delete(node_ *header, node_ *tailer, int position) {
	node_ *temp;
	temp = getnNode(header, tailer, position); // n��° ��带 �����´�.
	if(temp!=NULL)
		removeNode(temp); // ������ ��带 �����Ѵ�.
}


// n��° ���ĺ��� ����ϴ� �Լ�.
char getEntry(node_ *header, node_ *tailer, int position) {
	node_ *temp;
	temp = getnNode(header, tailer, position); // n��° ����� �ּҸ� �����´�.
	if (temp != NULL) { // n��° ��尡 �����ϴ� ��� ����Ѵ�.
		printf("%c\n", temp->alpha);
		return temp->alpha;
	}
	return '\0';
}


void printAllNode(node_ *header, node_* tailer) { // ��ü ����Ʈ�� ����ϴ� �Լ� (traverseList �� ����)
	node_ *temp = header->next;
	while (temp != tailer) { // ������尡 �Ǳ� ������ ����Ѵ�.
		printf("%c", temp->alpha);
		temp = temp->next;
	}
	printf("\n");
	return;
}


void freeList(node_ *header, node_* tailer) { // ��ü����Ʈ�� �����Ҵ� �����ϴ� �Լ�.
	node_ *temp = header->next;
	tailer->next = NULL;
	while (header != tailer) { // ������尡 �Ǳ� ������ �����Ѵ�.
		free(header);
		header = temp;  // �̸� temp�� ��Ƴ� ���� ����� �ּҸ� �����´�.
		temp = temp->next; // temp�� ���� ����� �ּҸ� ��´�.
	}
	free(tailer); // �ϳ� �����ִ� ������带 �����Ҵ� �����Ѵ�.
	return;

}


int main() {
	int n;
	char menu;
	int position;
	char input;
	node_ *header=NULL, *tailer=NULL;
	initList(&header, &tailer);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c%c", &menu, &menu);
		if (menu == 'A') {
			scanf("%d%c%c", &position, &input, &input);
			add(header, tailer, position, input);
		}
		else if (menu == 'D') {
			scanf("%d", &position);
			_delete(header, tailer, position);
		}
		else if (menu == 'G') {
			scanf("%d", &position);
			getEntry(header, tailer, position);
		}
		else if (menu == 'P') {
			printAllNode(header, tailer);
		}
		else
			break;
	}
	freeList(header, tailer);
	return 0;


}
