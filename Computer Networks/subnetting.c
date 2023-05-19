#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fn(int size, int n)
{
    int data[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }

    for (int i = 0; n > 0; i++)
    {
        data[i] = n % 2;
        n = n / 2;
    }

    int d;
    for (int j = size - 1; j >= 0; j -= 8)
    {
        d = 0;
        for (int i = 0; i < 8; i++)
        {
            if (data[j - i] == 1)
            {
                d += pow(2, 7 - i);
            }
        }
        printf(".%d", d);
    }
}

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

    int sn;
    printf("Enter no. of subnets: ");
    scanf("%d", &sn);

    float k = log2(sn);
    if (k != ceil(k))
    {
        printf("Only even powers of 2 subnets can be created");
        sn = pow(2, ceil(k));
        printf("\nNo. of subnets: %d\n", sn);
    }

    int flag = 0;
    if (data[7] == 0)
    {
        printf("\nClass A");
        flag = 24;
    }
    else if (data[7] == 1 && data[6] == 0)
    {
        printf("\nClass B");
        flag = 16;
    }
    else if (data[7] == 1 && data[6] == 1 && data[5] == 0)
    {
        printf("\nClass C");
        flag = 8;
    }
    else if (data[7] == 1 && data[6] == 1 && data[5] == 1 && data[4] == 0)
    {
        printf("\nClass D");
        printf("\nDoesn't have any subnets");
        flag = 0;
    }
    else
    {
        printf("\nClass E");
        printf("\nDoesn't have any subnets");
        flag = 0;
    }

    if (flag)
    {
        printf("\nTotal number of IP addresses(no. of subnets): %d", sn);
        int x = (int)(pow(2, flag) / sn);
        printf("\nTotal no. of hosts(per subnet): %d", x);
        printf("\nRange of IP Address: ");
        printf("\nInterface\tSubnet ID\tBroadcast ID");

        int c = -1;
        for (int i = 0; i < sn; i++)
        {
            printf("\n%d\t", i + 1);
            if (flag == 24)
            {
                printf("%d", a[0]);
            }
            else if (flag == 16)
            {
                printf("%d.%d", a[0], a[1]);
            }
            else
            {
                printf("%d.%d.%d", a[0], a[1], a[2]);
            }
            fn(flag, c + 1);

            printf("\t\t");
            c += x;
            if (flag == 24)
            {
                printf("%d", a[0]);
            }
            else if (flag == 16)
            {
                printf("%d.%d", a[0], a[1]);
            }
            else
            {
                printf("%d.%d.%d", a[0], a[1], a[2]);
            }
            fn(flag, c);
        }

        printf("\nSubnet Mask: ");
        if (flag == 24)
        {
            printf("255");
        }
        else if (flag == 16)
        {
            printf("255.255");
        }
        else
        {
            printf("255.255.255");
        }
        c -= x;
        fn(flag, c + 1);
    }

    return 0;
}