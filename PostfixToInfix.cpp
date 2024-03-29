// Q: Stack Postfix to Infix Conversion.

#include <iostream>
#include <cstring>
using namespace std;

struct node
{
    char data;
    node *next;
};

class stack

{
private:
    node *head;

public:
    stack()
    {
        head = NULL;
    }
    void push(char a)
    {
        node *temp = new node();
        temp->data = a;
        temp->next = head;
        head = temp;
    }
    char pop()
    {
        node *temp = head;
        head = temp->next;
        char a = temp->data;
        delete temp;
        return a;
    }
    char see_top()
    {
        if (is_empty())
            return '0';
        node *temp = head;
        return (temp->data);
    }
    int is_empty()
    {
        if (head == NULL)
            return 1;
        else
            return 0;
    }
};
int is_digit(char a)
{
    if (a >= '0' && a <= '9')
        return 1;
    else
        return 0;
}
int is_operand(char a)
{
    switch (a)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return 1;
    default:
        return 0;
    }
}
void reverse(char a[], int l)
{
    int i = 0;
    stack b;
    for (int j = 0; j < l; j++)
    {
        b.push(a[j]);
    }
    while (!b.is_empty())
        a[i++] = b.pop();
    return;
}


int main()
{
    int i, l, j = 0;
    char exp[100], infix[100];
    stack s;
    cout << "\nEnter a Postfix Expression : ";
    cin.getline(exp, 100);
    l = strlen(exp);
    reverse(exp, l);
    for (i = 0; i < l; i++)
    {
        if (is_digit(exp[i]))
        {
            infix[j++] = exp[i];
            if (i == l - 1)
                break;
            infix[j++] = s.pop();
        }
        else
            s.push(exp[i]);
    }

    while (!s.is_empty())
        infix[j++] = s.pop();
    reverse(infix, l);
    cout << "\nInfix is : ";

    for (i = 0; i < l; i++)
        cout << infix[i];
    cout << endl;
    return 0;
}