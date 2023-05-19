// 1. Implement an integer stack using Linked List.
//    PUSH and POP operations should be clearly defined.
//    WAP to calculate the factorial of a number N using the above - defined stack.
//    The number N should be taken as user input.
// cs20b1100 K.Anuj
// Complexity: O(n)

#include <stdio.h> 
#include <stdlib.h>

struct stack
{
    unsigned long long int data;
    struct stack *next;
} *top;

void push(int element)
{
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    if (element != 1)
    {
        return push(element - 1);
    }
}

void pop(int N)
{
    if (!top)
    {
        printf("stack is empty!\n");
    }
    else
    {
        struct stack *topNode;
        for (int i = 1; i < N; ++i)
        {
            topNode = top;
            top = top->next;
            top->data = (top->data * topNode->data);
            free(topNode);
        }
    }
}

int main()
{
    int n;
    printf("enter n value for n!:\n");
    scanf("%d", &n);
    push(n);
    pop(n);
    printf("\nvalue of n! = %llu", top->data);
    free(top);
}
