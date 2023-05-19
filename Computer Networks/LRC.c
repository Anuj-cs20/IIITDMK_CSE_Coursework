#include <stdio.h>

int main()
{
    int m;
    printf("Enter no of bits in a sessions: ");
    scanf("%d", &m);

    int data_len;
    printf("Enter length of the DATA(length should be a multiple of %d): ", m);
    scanf("%d", &data_len);

    while (data_len % m != 0)
    {
        printf("Enter length of the DATA(length should be a multiple of %d): ", m);
        scanf("%d", &data_len);
    }

    int data[data_len + m];
    printf("Enter DATA: ");
    for (int i = data_len + m - 1; i >= m; i--)
    {
        scanf("%d", &data[i]);
    }

    int cont = 0;
    for (int i = data_len + m - 1; i >= data_len; i--)
    {
        int j;
        for (j = i; j > i % m; j -= m)
        {
            if (data[j] == 1)
            {
                cont++;
            }
        }

        // even parity
        if (cont % 2 == 0)
        {
            data[j] = 0;
        }
        else
        {
            data[j] = 1;
        }
        cont = 0;
    }

    printf("The sender DATA: ");
    for (int i = data_len + m - 1; i >= 0; i--)
    {
        printf("%d", data[i]);
    }

    int redata[data_len + m];
    printf("\nEnter receiver DATA: ");
    for (int i = data_len + m - 1; i >= 0; i--)
    {
        scanf("%d", &redata[i]);
    }

    int flag = 0;
    cont = 0;
    for (int i = data_len + m - 1; i >= data_len; i--)
    {
        int j;
        for (j = i; j > i % m; j -= m)
        {
            if (redata[j] == 1)
            {
                cont++;
            }
        }

        // even parity
        if (cont % 2 == 0 && redata[j] != 0)
        {
            flag = 1;
        }

        if (cont % 2 != 0 && redata[j] != 1)
        {
            flag = 1;
        }
        cont = 0;
    }

    if (flag == 1)
    {
        printf("Error");
    }
    else
    {
        printf("No Error");
    }

    return 0;
}
