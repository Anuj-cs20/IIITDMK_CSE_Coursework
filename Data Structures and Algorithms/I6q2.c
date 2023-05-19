// 2. Implement a character stack using Linked List.
//    PUSH and POP operations should be clearly defined.
//    WAP to take a random string as user input.
//    The string should be a combination of alphabets.
//    Traverse through the string and do the following operations.
//    • If a consonant is encounterd, PUSH to the stack.
//    • If a vowel is encounterd, POP from the stack
//    • Show the content of the top of the stack after each operation
// cs20b1100 K.Anuj
// Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char alphabet;
    struct stack *next;
} *top;

void push(int ch)
{
    if (top == NULL)
    {
        top = (struct stack *)malloc(sizeof(struct stack));
        top->alphabet = ch;
        top->next = NULL;
    }
    else
    {
        struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
        newNode->alphabet = ch;
        newNode->next = top;
        top = newNode;
    }
    printf("content of the top of the stack is : %c\n", top->alphabet);
}

void pop()
{
    struct stack *tmp;
    if (top == NULL)
    {
        printf("stack is empty!\n");
    }
    else if (top->next == NULL)
    {
        tmp = top;
        top = NULL;
        free(tmp);
        printf("stack is empty!\n");
    }
    else
    {
        tmp = top;
        top = top->next;
        free(tmp);
        printf("content of the top of the stack is : %c\n", top->alphabet);
    }
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

int main()
{
    int n;
    char str[100];
    puts("Enter the string of alphabets: ");
    scanf("%s", str);
    n = strlen(str);
    for (size_t i = 0; i < n; ++i)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            pop();
        }
        else
        {
            push(str[i]);
        }
    }
    freeStack();
    return 0;
}