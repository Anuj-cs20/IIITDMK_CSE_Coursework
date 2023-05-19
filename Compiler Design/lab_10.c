// cs20b1100
// K.Anuj

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void substring(char exp[], int st)
{
    int i;
    for (i = 0; exp[i + st] != '\0'; i++)
        exp[i] = exp[i + st];
    exp[i] = '\0';
}

// function for getting the variable name
void getvar(char exp[], char v[])
{
    int i, j = 0;
    for (i = 0; exp[i] != '\0'; i++)
        if (isalpha(exp[i]))
            v[j++] = exp[i];
        else
            break;
    v[j] = '\0';
}

// main function
int main()
{
    // declaring data
    char basic[100][100], var[3][100], op;
    int i, j;

    // taking input of the 3 address code
    printf("Enter the Three Address Code:\n");
    for (i = 0;; i++)
    {
        scanf("%s", basic[i]);
        if (strcmp(basic[i], "exit") == 0)
            break;
    }

    // printing the result
    printf("\nThe Equivalent Assembly Code is:");
    for (j = 0; j < i; j++)
    {
        getvar(basic[j], var[0]);
        substring(basic[j], strlen(var[0]) + 1);
        getvar(basic[j], var[1]);
        printf("\nMov R0,%s", var[1]);
        op = basic[j][strlen(var[1])];
        substring(basic[j], strlen(var[1]) + 1);
        getvar(basic[j], var[2]);
        switch (op)
        {
        case '+':
            printf("\nAdd");
            break;
        case '-':
            printf("\nSub");
            break;
        case '*':
            printf("\nMul");
            break;
        case '/':
            printf("\nDiv");
            break;
        }
        printf(" R0,%s", var[2]);
        printf("\nMov %s,R0", var[0]);
    }
    return 0;
}