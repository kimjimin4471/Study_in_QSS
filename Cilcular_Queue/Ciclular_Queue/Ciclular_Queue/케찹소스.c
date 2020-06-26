#include<stdio.h>
#include<string.h>
#define SIZE 4

int circule_queue[SIZE], back = 0, front = 0, sweat = 1;

void enqueue(int num)
{

	if ((front + 1) % SIZE == back)
	{
		printf("��ȭ �����Դϴ�.\n");
		sweat = 0;
	}
	else
	{
		front = (front + 1) % SIZE;
		circule_queue[front] = num;
	}
}

void dequeue()
{
	if (front == back)
	{
		printf("���� �����Դϴ�.\n");
	}
	else
	{
		back = (back + 1) % SIZE;
		printf("��µ� �� : %d\n", circule_queue[back]);
		circule_queue[back] = NULL;
	}
}

int main()
{
	int test, i, num;
	char ch; //��ɾ� �Է�
	printf("�׽�Ʈ ���̽� :");
	scanf("%d", &test); //�׽�Ʈ ���̽�
	while (sweat)
	{
		while (getchar() != '\n');
		printf("��ɾ� �Է� :");
		scanf("%c", &ch);
		if (ch == 'e')
		{
			printf("�� �Է� :");
			scanf("%d", &num);
			enqueue(num);
		}
		else if (ch == 'd')
		{
			dequeue();
		}
	}
}