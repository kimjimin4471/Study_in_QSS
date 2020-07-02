#include<stdio.h>

void check_id(char* check);

int main()
{
	char check[101];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", check);
		check_id(check);
	}
	return 0;
}

void check_id(char* check)
{
	int che = 1;
	char ch = '\0';
	for (int i = 0; check[i] != '\0'; i++)
	{
		if (ch == '@' && check[i] == '@')
			che = 0;
		if (check[i] <= '/' && check[i] >= '!')
			if (check[i] != '-' && check[i] != '.')
				che = 0;
		if (check[i] >= ':' && check[i] <= '?')
			che = 0;
		if (check[i] >= '[' && check[i] <= '\'')
			che = 0;
		if (check[i] >= '{' && check[i] <= '~')
			che = 0;
		if (i == 0 && check[i] == '@')
			che = 0;
		if (check[i + 1] == '\0' && check[i] == '@')
			che = 0;
		if (check[i] == '@')
			ch = '@';
	}
	if (ch != '@')
		che = 0;
	if (che)
		printf("Yes\n");
	else
		printf("No\n");
}