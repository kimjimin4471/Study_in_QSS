#include<stdio.h>
#include <stdlib.h>

typedef struct Node		//���
{
	struct Node* next;
	int data;
}Node;

typedef struct List		//���
{
	Node* head;
}List;

typedef Node* PNode;

void init_node(PNode node, PNode next, int data)	// (��� , NEXT�� ���ϰ�, data) 
{ 
	node->next = next;
	node->data = data;
}

void init_list(List* list)	//��� �ʱ�ȭ
{
	list->head = NULL;
}

void push_front(List* list, int data)	//���Ḯ��Ʈ�� �� �տ� ��� �߰�
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

void push_back(List* list, int data)	//���Ḯ��Ʈ�� �� ���� ��� �߰�
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

void nodePrint(List* list)	//���Ḯ��Ʈ�� ����ϰ� �����Ҵ��� Ǯ���ش�.
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

int get(List* list, int num)	//Ư�� �ε��� ��ȣ�� �ִ� ���� ���
{
	PNode curr = list->head;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	return curr->data;
}

void delete(List* list, int index)	//Ư�� �ε��� ��ȣ�� �ִ� ��带 ����
{
	if (list->head == NULL) return;
	PNode curr = list->head;
	if (index == 0)
	{
		PNode tmp = curr->next;
		free(curr);
		list->head = tmp;
		return;
	}
	for (int i = 0; i < index -1; i++)
	{
		curr = curr->next;
	}
	PNode tmp = curr ->next;
	curr->next = tmp ->next;
	free(tmp);
}

void push_index(List* list, int index, int data)	//Ư�� �ε��� ��ȣ�� ��带 �����ϰ� �����͸� �ִ´�.
{
	PNode newNode = (PNode)malloc(sizeof(Node));
	newNode->data = data;
	PNode curr = list->head;
	for (int i = 0; i < index - 1; i++)
		curr = curr->next;
	PNode tmp = curr->next;
	curr->next = newNode;
	newNode->next = tmp;
}

int main() {
	List list;
	init_list(&list);
	int n, data, num, result;
	printf("1 = �� �� 2 = �� �� 3 = ��� Ž�� 4 = ��°� ���� 5 = ��� ���� 6 = Ư�� �ε��� ����\n");
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
		case 5:
			printf("������ index��ȣ :");
			scanf("%d", &num);
			delete(&list, num);
			break;
		case 6:
			printf("������ ��ȣ�� ������ :");
			scanf("%d %d", &num, &data);
			push_index(&list, num, data);
			break;
		}
	}
}
