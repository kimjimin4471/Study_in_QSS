#include<stdio.h>
#include<string.h>
#define SIZE 4

int circule_queue[SIZE], back = 0, front = 0, sweat = 1;

void enqueue(int num)
{

	if ((front + 1) % SIZE == back)
	{
		printf("포화 상태입니다.\n");
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
		printf("공백 상태입니다.\n");
	}
	else
	{
		back = (back + 1) % SIZE;
		printf("출력된 값 : %d\n", circule_queue[back]);
		circule_queue[back] = NULL;
	}
}

int main()
{
	int test, i, num;
	char ch; //명령어 입력
	printf("테스트 케이스 :");
	scanf("%d", &test); //테스트 게이스
	while (sweat)
	{
		while (getchar() != '\n');
		printf("명령어 입력 :");
		scanf("%c", &ch);
		if (ch == 'e')
		{
			printf("수 입력 :");
			scanf("%d", &num);
			enqueue(num);
		}
		else if (ch == 'd')
		{
			dequeue();
		}
	}
}