//stack prefix to infix

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


#define MAX 20
char str[MAX], stack[MAX];
int top = -1;
void push(char c)
{
    stack[++top] = c;
}

char pop()

{
    return stack[top--];
}

void post_in()

{
    int n, i, j = 0;
    char a, b, op, x[20];
    printf("Enter the Postfix Expression: \n");
    fflush(stdin);
    gets(str);
    strrev(str);
    n = strlen(str);
    for (i = 0; i < MAX; i++)
        stack[i] = '\0';
    printf("Infix Expression is: \t");
    for (i = 0; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            push(str[i]);
        }
        else
        {
            x[j] = str[i];
            j++;
            x[j] = pop();
            j++;
        }
    }
    x[j] = str[top--];
    strrev(x);
    printf("%s\n", x);
}

void pre_in()
{
    int n, i;
    char a, b, op;
    printf("Enter the Prefix Expression: ");
    fflush(stdin);
    gets(str);
    n = strlen(str);
    for (i = 0; i < MAX; i++)
        stack[i] = '\0';
    printf("Infix Expression is: ");
    for (i = 0; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            push(str[i]);
        }
        else
        {
            op = pop();
            a = str[i];
            printf("%c%c", a, op);
        }
    }
    printf("%c\n", str[top--]);
}

void main()

{
    int ch;
    while (1)
    {
        printf("Enter Choice:\n [1] for Prefix to Infix \n [2] for Postfix to Infix \n [3] to Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            pre_in();
            break;
        }
        case 2:
        {
            post_in();
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
            printf("Wrong Choice!\n");
        }
        printf("Enter [1] to Continue, [0] to Exit\n");
        scanf("%d", &ch);
        if (ch == 0)
            break;

            
    }
}