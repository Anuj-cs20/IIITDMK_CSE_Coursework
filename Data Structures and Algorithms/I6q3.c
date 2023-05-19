// 3. Evaluation of a Prefix expression using stack(Linked List implementation).
//    Your program should do the following.
//    • User should take an infix expression as input
//    • WAP to convert this infix expression to Prefix expression
//    • WAP to evaluate the above Prefix expression using stack.
// cs20b1100 K.Anuj
// Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct stack
{
    char ele;
    struct stack *next;
};

struct stack1
{
    char c;
    int d;
    struct stack1 *next;
};

struct stack2
{
    float f;
    struct stack2 *next;
};

struct stack *top = NULL;
struct stack1 *top1 = NULL;
struct stack2 *top2 = NULL;

void push(char x)
{
    if (top == NULL)
    {
        top = (struct stack *)malloc(sizeof(struct stack));
        top->ele = x;
        top->next = NULL;
    }
    else
    {
        struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
        newNode->ele = x;
        newNode->next = top;
        top = newNode;
    }
}

void push1(char x, int q)
{
    if (top1 == NULL)
    {
        top1 = (struct stack1 *)malloc(sizeof(struct stack1));
        top1->d = q;
        top1->c = x;
        top1->next = NULL;
    }
    else
    {
        struct stack1 *newNode = (struct stack1 *)malloc(sizeof(struct stack1));
        newNode->c = x;
        newNode->d = q;
        newNode->next = top1;
        top1 = newNode;
    }
}

void push2(float x)
{
    if (top2 == NULL)
    {
        top2 = (struct stack2 *)malloc(sizeof(struct stack2));
        top2->f = x;
        top2->next = NULL;
    }
    else
    {
        struct stack2 *newNode = (struct stack2 *)malloc(sizeof(struct stack2));
        newNode->f = x;
        newNode->next = top2;
        top2 = newNode;
    }
}

char pop()
{
    struct stack *tmp;
    char item;
    if (top == NULL)
    {
        item = 0;
    }
    else if (top->next == NULL)
    {
        tmp = top;
        item = top->ele;
        top = NULL;
        free(tmp);
    }
    else
    {
        tmp = top;
        item = top->ele;
        top = top->next;
        free(tmp);
    }
    return item;
}

float pop2()
{
    struct stack2 *tmp;
    float item;
    if (top2 == NULL)
    {
        item = 0;
    }
    else if (top2->next == NULL)
    {
        tmp = top2;
        item = top2->f;
        top2 = NULL;
        free(tmp);
    }
    else
    {
        tmp = top2;
        item = top2->f;
        top2 = top2->next;
        free(tmp);
    }
    return item;
}

void revereseArray(char arr[], int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

void evaluate()
{
    char ch;
    float val;
    float A, B;
    while (top1 != NULL)
    {
        ch = top1->c;
        if (top1->d)
        {
            push2(top1->d);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            A = pop2();
            B = pop2();
            switch (ch)
            {
            case '*':
                val = B * A;
                break;
            case '/':
                val = (float)A / B;
                break;
            case '+':
                val = B + A;
                break;
            case '-':
                val = A - B;
                break;
            }
            push2(val);
        }
        top1 = top1->next;
    }
    printf(" \nResult of expression evaluation : % f \n", pop2());
}

void reverseList()
{
    struct stack1 *temp = NULL, *nextNode = NULL;
    while (top1)
    {
        nextNode = top1->next;
        top1->next = temp;
        temp = top1;
        top1 = nextNode;
    }
    top1 = temp;
}

void freeStack()
{
    struct stack *temp;
    while (top)
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void freeStack1()
{
    struct stack1 *temp;
    while (top1)
    {
        temp = top1;
        top1 = top1->next;
        free(temp);
    }
}

int main()
{
    char exp[100];
    char x;
    printf("Enter the expression : ");
    scanf("%s", exp);
    printf("\n");
    int n, i = -1, count = 0;
    n = strlen(exp);
    revereseArray(exp, 0, n - 1);
    for (int j = 0; j < n; ++j)
    {
        if (isalnum(exp[j]))
        {
            int count1 = 1;
            int h = exp[j] - '0';
            while (isdigit(exp[j]) == isdigit(exp[j + 1]))
            {
                int s = exp[j + 1] - '0';
                h += s * pow(10, count1);
                ++count;
                ++count1;
                ++j;
            }
            push1('0', h);
        }
        else if (exp[j] == ')')
        {
            push(exp[j]);
        }
        else if (exp[j] == '(')
        {
            while ((x = pop()) != ')')
            {
                push1(x, 0);
            }
        }
        else
        {
            while (top != NULL && priority(top->ele) >= priority(exp[j]))
            {
                push1(pop(), 0);
            }

            push(exp[j]);
        }
    }

    while (top != NULL)
    {
        push1(pop(), 0);
    }

    puts("prefix is :");
    struct stack1 *temp = top1;
    while (temp != NULL)
    {
        if (temp->c != '0')
        {
            printf("%c", temp->c);
        }
        else
        {
            printf("%d", temp->d);
        }
        temp = temp->next;
    }
    freeStack();
    reverseList();
    evaluate();
    freeStack1();
    return 0;
}