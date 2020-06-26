#include<stdio.h>
#include<string.h>
int queue[10000], fro = 0, ba = 0;

void push()
{
    scanf("%d", &queue[fro]);
    fro++;
}

void pop()
{
    if (queue[fro - 1] != 0)
    {
        printf("%d\n", queue[ba]);
        queue[ba] = 0;
        ba++;
    }
    else
    {
        printf("-1\n");
    }
}

void size()
{
    if (fro - ba <= 0)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", fro - ba);
    }
}

void empty()
{
    if (fro - ba > 0)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
}

void front()
{
    if (fro - ba <= 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", queue[ba]);
    }
}

void back()
{
    if (fro - ba <= 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", queue[fro - 1]);
    }
}

int main()
{
    int i, n;
    char ch[6];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", ch);
        if (!strcmp(ch, "push"))
        {
            push();
        }
        else if (!strcmp(ch, "pop"))
        {
            pop();
        }
        else if (!strcmp(ch, "size"))
        {
            size();
        }
        else if (!strcmp(ch, "empty"))
        {
            empty();
        }
        else if (!strcmp(ch, "front"))
        {
            front();
        }
        else if (!strcmp(ch, "back"))
        {
            back();
        }
    }
    return 0;
}