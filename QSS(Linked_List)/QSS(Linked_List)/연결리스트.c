#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

typedef struct List {
	Node* head;
}List;

typedef Node* PNode;

void init_node(PNode node, PNode next, int data) { // (��� , NEXT�� ���ϰ�, data)
	node->next = next;
	node->data = data;
}

void init_list(List* list) {
	list->head = NULL;
}

void push_front(List* list, int data) 
{
	if (list->head == NULL) 
	{
		list->head = (PNode)malloc(sizeof(Node));
		init_node(list->head, NULL, data);
	}
	else 
	{
		PNode newNode = (PNode)malloc(sizeof(Node));
		init_node(newNode, list->head, data);
		list->head = newNode;
	}
}

void push_back(List* list, int data)
{
	if (list->head == NULL)
	{
		list->head = (PNode)malloc(sizeof(Node));
		init_node(list->head, NULL, data);
	}
	else
	{
		PNode newNode = (PNode)malloc(sizeof(Node));
		init_node(newNode, NULL, data);
		PNode curr = list->head;
		for (; curr->next != NULL; curr = curr->next);
		curr->next = newNode;
	}
}

void nodePrint(List* list)
{
	PNode curr = list->head;
	while (curr->next != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	printf("%d\n", curr->data);

	curr = list->head;
	PNode tmp = curr;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(tmp);
		tmp = curr;
	}
}

int get(List* list, int num)
{
	PNode curr = list->head;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	return curr->data;
}

int main() {
	List list;
	init_list(&list);
	int n, data, num, result;
	printf("1 = �� �� 2 = �� �� 3 = ��� Ž�� 4 = ��°� ����\n");
	while (1)
	{
		printf("��ɾ� �Է� : ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("���� �Է� :");
			scanf("%d", &data);
			push_front(&list, data);
			break;
		case 2:
			printf("���� �Է� :");
			scanf("%d", &data);
			push_back(&list, data);
			break;
		case 3:
			printf("Ž���� ��� ��ȣ �Է� : ");
			scanf("%d", &num);
			result = get(&list, num);
			printf("%d\n", result);
			break;
		case 4:
			nodePrint(&list);
			return 0;
		}
	}
}
