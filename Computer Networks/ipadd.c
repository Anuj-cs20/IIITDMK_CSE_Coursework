#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[15];
    printf("Enter IP Address(Dotted Decimal Notation): ");
    scanf("%s", s);

    int a[] = {0, 0, 0, 0}, j = 3;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == '.')
        {
            j--;
        }
        else
        {
            a[j] = atoi(&s[i]);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (a[i] < 0 || a[i] > 255)
        {
            printf("Wrong IP Address");
            return 0;
        }
    }

    int n = a[0];
    int data[] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; n > 0; i++)
    {
        data[i] = n % 2;
        n = n / 2;
    }

    if (data[7] == 0)
    {
        printf("Class A");
    }
    else if (data[7] == 1 && data[6] == 0)
    {
        printf("Class B");
    }
    else if (data[7] == 1 && data[6] == 1 && data[5] == 0)
    {
        printf("Class C");
    }
    else if (data[7] == 1 && data[6] == 1 && data[5] == 1 && data[4] == 0)
    {
        printf("Class D");
    }
    else
    {
        printf("Class E");
    }

    return 0;
}