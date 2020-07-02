#include<stdio.h>
#include <stdlib.h>

typedef struct Node		//노드
{
	struct Node* next;
	int data;
}Node;

typedef struct List		//헤드
{
	Node* head;
}List;

typedef Node* PNode;

void init_node(PNode node, PNode next, int data)	// (노드 , NEXT에 붙일거, data) 
{ 
	node->next = next;
	node->data = data;
}

void init_list(List* list)	//헤드 초기화
{
	list->head = NULL;
}

void push_front(List* list, int data)	//연결리스트의 맨 앞에 노드 추가
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

void push_back(List* list, int data)	//연결리스트의 맨 끝에 노드 추가
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

void nodePrint(List* list)	//연결리스트를 출력하고 동적할당을 풀어준다.
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

int get(List* list, int num)	//특정 인덱스 번호에 있는 정보 출력
{
	PNode curr = list->head;
	for (int i = 0; i < num; i++)
		curr = curr->next;
	return curr->data;
}

void delete(List* list, int index)	//특정 인덱스 번호에 있는 노드를 삭제
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

void push_index(List* list, int index, int data)	//특정 인덱스 번호에 노드를 생성하고 데이터를 넣는다.
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
	printf("1 = 맨 앞 2 = 맨 끝 3 = 노드 탐색 4 = 출력과 종료 5 = 노드 삭제 6 = 특정 인덱스 삽입\n");
	while (1)
	{
		printf("명령어 입력 : ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("정보 입력 :");
			scanf("%d", &data);
			push_front(&list, data);
			break;
		case 2:
			printf("정보 입력 :");
			scanf("%d", &data);
			push_back(&list, data);
			break;
		case 3:
			printf("탐색할 노드 번호 입력 : ");
			scanf("%d", &num);
			result = get(&list, num);
			printf("%d\n", result);
			break;
		case 4:
			nodePrint(&list);
			return 0;
		case 5:
			printf("삭제할 index번호 :");
			scanf("%d", &num);
			delete(&list, num);
			break;
		case 6:
			printf("삽입할 번호와 데이터 :");
			scanf("%d %d", &num, &data);
			push_index(&list, num, data);
			break;
		}
	}
}
