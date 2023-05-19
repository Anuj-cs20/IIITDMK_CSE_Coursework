// cs20b1100
// K.Anuj
// Write a C program to simulate lexical analyzer for validating operators

#include <stdio.h>

int main()
{
    char s[2];
    printf("\nEnter any operator(size:[1,2]): ");
    scanf("%c", &s[0]);
    scanf("%c", &s[1]);
    printf("Entered Data: %s", s);
    switch (s[0])
    {
    case '>':
        if (s[1] == '=')
            printf("\nGreater than or equal");
        else if (s[1] == '\n')
            printf("\nGreater than");
        else
            printf("\nNot a operator");
        break;
    case '<':
        if (s[1] == '=')
            printf("\n Less than or equal");
        else if (s[1] == '\n')
            printf("\nLess than");
        else
            printf("\nNot a operator");
        break;
    case '=':
        if (s[1] == '=')
            printf("\nEqual to");
        else if (s[1] == '\n')
            printf("\nAssignment");
        else
            printf("\nNot a operator");
        break;
    case '!':
        if (s[1] == '=')
            printf("\nNot Equal");
        else if (s[1] == '\n')
            printf("\nBit Not");
        else
            printf("\nNot a operator");
        break;
    case '&':
        if (s[1] == '&')
            printf("\nLogical AND");
        else if (s[1] == '\n')
            printf("\nBitwise AND");
        else
            printf("\nNot a operator");
        break;
    case '|':
        if (s[1] == '|')
            printf("\nLogical OR");
        else if (s[1] == '\n')
            printf("\nBitwise OR");
        else
            printf("\nNot a operator");
        break;
    case '+':
        if (s[1] == '\n')
            printf("\nAddition");
        else
            printf("\nNot a operator");
        break;
    case '-':
        if (s[1] == '\n')
            printf("\nSubstraction");
        else
            printf("\nNot a operator");
        break;
    case '*':
        if (s[1] == '\n')
            printf("\nMultiplication");
        else
            printf("\nNot a operator");
        break;
    case '/':
        if (s[1] == '\n')
            printf("\nDivision");
        else
            printf("\nNot a operator");
        break;
    case '%':
        if (s[1] == '\n')
            printf("\nModulus");
        else
            printf("\nNot a operator");
        break;
    default:
        printf("\nNot a operator");
    }

    return 0;
}