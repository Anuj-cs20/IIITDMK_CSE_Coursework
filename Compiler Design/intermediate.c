// 9.Given a boolean expression as an input, write a program to generate intermediate code for that boolean expression by using short circuit evaluation.

#include <stdio.h>

int Isop(char c)
{
    if (c == '>' || c == '<' || c == '|' || c == '&')
        return 1;
    return 0;
}

char pop(char st[], int *top)
{
    return st[(*top)--];
}

void push(char st[], int *top, char c)
{
    st[++(*top)] = c;
}

char Top(char st[], int top)
{
    return st[top];
}

void infTopos(char inf[], char pos[])
{
    char st[100];
    int top = -1, i, j = 0;
    for (i = 0; inf[i] != '\0'; i++)
    {
        if (inf[i] == '(')
            push(st, &top, inf[i]);
        else if (inf[i] == ')')
        {
            while (Top(st, top) != '(')
                pos[j++] = pop(st, &top);
            pop(st, &top);
        }
        else if (Isop(inf[i]))
        {
            while (top != -1 && Top(st, top) != '(' && Top(st, top) != '|' && Top(st, top) != '&')
                pos[j++] = pop(st, &top);
            push(st, &top, inf[i]);
        }
        else
            pos[j++] = inf[i];
    }
    while (top != -1)
        pos[j++] = pop(st, &top);
    pos[j] = '\0';
}

void ICG(char pos[])
{
    // Generating intermediate code
    char st[100];
    int top = -1, label = 1, temp = 1;
    for (int i = 0; pos[i] != '\0'; i++)
    {
        // wherever labels are required we need to assign them to value T and print it
        // For last label we need to print the next code
        if (Isop(pos[i]))
        {
            if (pos[i] == '|')
            {
                printf("if T%d goto L%d\n", temp, label);
                push(st, &top, label);
                // print the value for the label
                printf("T%d = 0\n", temp);
                printf("goto L%d\n", label + 1);
                printf("L%d: T%d = 1\n", label, temp);
                label++;
                temp++;
            }
            else if (pos[i] == '&')
            {
                printf("if not T%d goto L%d\n", temp, label);
                push(st, &top, label);
                // print the value for the label
                printf("T%d = 0\n", temp);
                printf("goto L%d\n", label + 1);
                printf("L%d: T%d = 1\n", label, temp);
                label++;
                temp++;
            }
            else
            {
                printf("if %c%c%c goto L%d\n", Top(st, top - 1), pos[i], Top(st, top), label);
                // Print the value for the label
                printf("T%d = 0\n", temp);
                printf("goto L%d\n", label + 1);
                printf("L%d: T%d = 1\n", label, temp);
                pop(st, &top);
                pop(st, &top);
                push(st, &top, label);
                label++;
            }
            // This is the case when the character is a variable
            // We will push the variable to the st
        }
        else
            push(st, &top, pos[i]);

        if (pos[i + 1] == '\0')
        {
            printf("T%d = 0\n", temp);
            printf("goto L%d\n", label);
            printf("L%d: T%d = 1\n", pop(st, &top), temp);
            printf("next code\n");
        }
    }
}

int main()
{
    char exp[100];
    printf("Enter the expression: ");
    scanf("%s", exp);
    char pos[100];
    infTopos(exp, pos);
    printf("\n");
    ICG(pos);
}