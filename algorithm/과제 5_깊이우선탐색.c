#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

typedef struct graphNode {    //�׷����� ���� ���� ����Ʈ�� ��� ���� ����
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;                   //������ ����
	graphNode* adjList_H[MAX_VERTEX];   //������ ���� ���� ����Ʈ�� ��� ��� �迭
	int visited[MAX_VERTEX];              //������ ���� �湮 ǥ�ø� ���� �迭
}graphType;

//////// << ���� ����
typedef struct stackNode {
	int data;
	struct stackNode *link;
}stackNode;

stackNode* top;

void push(int item)
{
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop()
{
	int item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n\n Stack is empty !\n");
		return -1;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}
//////// ���� ���� >>

void createGraph(graphType* g)       //���� �켱 Ž���� ���� �ʱ� ���� �׷��� ���� ����
{
	int v;
	g->n = 0;                      //�׷����� ���� ������ 0���� �ʱ�ȭ
	for (v = 0; v<MAX_VERTEX; v++) {
		g->visited[v] = FALSE;        //�׷����� ������ ���� �迭 visited�� FALSE�� �ʱ�ȭ
		g->adjList_H[v] = NULL;       //���� ����Ʈ�� ���� ��� ��� �迭�� NULL�� �ʱ�ȭ
	}
}

void insertVertex(graphType* g, int v)   //�׷��� g�� ���� v�� �����ϴ� ����
{
	if (((g->n) + 1)>MAX_VERTEX) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v)  //�׷��� g�� ���� (u, v)�� �����ϴ� ����
{
	graphNode* node;
	if (u >= g->n || v >= g->n) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g)    //�׷��� g�� ���� ���� ����Ʈ�� ����ϴ� ����
{
	int i;
	graphNode* p;
	for (i = 0; i<g->n; i++) {
		printf("\n\t���� %d�� ���� ����Ʈ", i);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %d", p->vertex );
			p = p->link;
		}
	}
}

void DFS_adjList(graphType* g, int v)    //�׷��� g���� ���� v�� ���� ���� �켱 Ž�� ����
{
	graphNode* w; // v�� ���� ����, w�� ��带 ����Ű�� �����ͺ���
	top = NULL;   // ���� top ����
	g->visited[v] = TRUE;
	
	//printf(" %d", v); // ��� ������ �ٷ� ó��, w�� ���� ��带 ����Ű�� ���� �ʽ��ϴ�.

	while (v != -1) //������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�, ������ �����̸� -1�� �����մϴ�.
	{      
		w = g->adjList_H[v]; // ���� v�� ����� �������� �̵���Ŵ
		
		while (w) // ���������� �ִ� ���� ����
		{
			if (g->visited[w->vertex] == 0)   //1) ���� ���� w�� �湮���� ���� ���
			{ 
				push(v); // ���� ��带 push
				g->visited[w->vertex] = TRUE; // visited�迭�� �湮�ߴٰ� ǥ��
				printf(" %d", w->vertex); // ���� ���
				v = w->vertex; // �湮�� �ű� ���� �̵�
				w = g->adjList_H[v]; // �űԳ���� ���������� �̵�
			}
			else //2) ���� ���� w�� �̹� �湮�� ������ ���
			{
				printf(" %d", w->vertex); // w�� �̵��� Ȯ���ϱ� ���� w�� ���� �������� �̵� ���� ����ϴ� ���� �߰��߽��ϴ�.
				w = w->link; // ���� �������� �̵�
			}
		}
		v = pop(); //���� �������� �� �̻� ��ȸ�� ������ ���� ������ ���� ��쿡 ���� pop
	}
}

void main()
{
	int i;
	graphType *G4 = (graphType *)malloc(sizeof(graphType));;
	createGraph(G4);

	for (i = 0; i<5; i++)        //�׷��� G5 ����
		insertVertex(G4, i);

	insertEdge(G4, 0, 2);
	insertEdge(G4, 0, 1);
	insertEdge(G4, 1, 3);
	insertEdge(G4, 1, 2);
	insertEdge(G4, 1, 0);
	insertEdge(G4, 2, 4);
	insertEdge(G4, 2, 3);
	insertEdge(G4, 2, 1);
	insertEdge(G4, 2, 0);
	insertEdge(G4, 3, 2);
	insertEdge(G4, 3, 1);
	insertEdge(G4, 4, 2);
	printf("\n G4�� ���� ����Ʈ ");
	print_adjList(G4);

	printf("\n\n///////////////\n\n���� �켱 Ž���� w�� ��ġ ���� >> ");
	DFS_adjList(G4, 0);     //0�� ������ ���� A���� ���� �켱 Ž�� ����
	
	printf("\n");
	
}
