/*
    4. Write a C program to convert a given simple mathematical expression
    into prefix notation. You can assume some simple conditions for input
    like only 3 to 4 components are there in the expression.

    Example = If the input string is E=(X*Y)-(4Z+X) then the output
    must be E=  - * X Y + Z X.

*/

#include <stdio.h>
char global[50];
int top = -1;

void push(char ch)
{
    top++;
    global[top] = ch;
}

char pop()
{
    int ch = global[top];
    top--;
    return ch;
}

int isOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '^':
    case '/':
    case '(':
    case ')':
        return 0;
        break;
    default:
        return 1;
    }
}

int preccedence(char symbol)
{
    if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("Length of the expression: ");
    scanf("%d", &n);

    printf("expression: ");
    char arr[n], str[n];
    scanf("%s", arr);

    char el;
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (isOperator(arr[i]))
        {
            str[j] = arr[i];
            j++;
        }
        else if (arr[i] == ')')
        {
            push(arr[i]);
        }
        else if (arr[i] == '(')
        {
            while (global[top] != ')')
            {
                str[j] = pop();
                j++;
            }
            pop();
        }
        else if (top != -1 && (preccedence(global[top]) >= preccedence(arr[i])))
        {
            while (top != -1)
            {
                str[j] = pop();
                j++;
            }
            push(arr[i]);
        }
        else
        {
            push(arr[i]);
        }
    }
    while (top != -1)
    {
        str[j] = pop();
        j++;
    }

    printf("Prefix: ");
    for (int i = j - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return 0;
}