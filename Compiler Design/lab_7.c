// cs20b1100
// K.Anuj
// Write a C program to recognize strings under 'a*', 'a*b+', 'abb'

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[20], c;
    int state = 0, i = 0;
    printf("\nEnter a string: ");
    scanf("%s", s);
    while (s[i] != '\0')
    {
        switch (state)
        {
        case 0:
            c = s[i++];
            if (c == 'a')
                state = 1;
            else if (c == 'b')
                state = 5;
            else
                state = 6;
            break;
        case 1:
            c = s[i++];
            if (c == 'a')
                state = 2;
            else if (c == 'b')
                state = 3;
            else
                state = 6;
            break;
        case 2:
            c = s[i++];
            if (c == 'a')
                state = 2;
            else if (c == 'b')
                state = 5;
            else
                state = 6;
            break;
        case 3:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 4;
            else
                state = 5;
            break;
        case 4:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 5;
            else
                state = 6;
            break;
        case 5:
            c = s[i++];
            if (c == 'a')
                state = 6;
            else if (c == 'b')
                state = 5;
            else
                state = 6;
            break;
        case 6:
            printf("\n%s is not recognised.", s);
            exit(0);
        }
    }
    if ((state == 1) || (state == 2))
        printf("\n%s is accepted under rule 'a*'", s);
    else if ((state == 3) || (state == 5))
        printf("\n%s is accepted under rule 'a*b+'", s);
    else if (state == 4)
        printf("\n%s is accepted under rule 'abb'", s);
    else
        printf("\n%s is not recognised.", s);
    return 0;
}