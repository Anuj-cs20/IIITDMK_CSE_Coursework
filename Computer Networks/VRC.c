/*
    Even parity means the total number of 1s in data is to be even and
    odd parity means the total number of 1s in data is to be odd.
*/

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

    int data[data_len + (data_len / m)], cont = 0;
    printf("Enter DATA: ");
    for (int i = data_len + (data_len / m) - 1; i >= 0; i--)
    {
        if (i % (m + 1) == 0)
        {
            // even parity
            if (cont % 2 == 0)
            {
                data[i] = 0;
            }
            else
            {
                data[i] = 1;
            }
            cont = 0;
        }
        else
        {
            scanf("%d", &data[i]);
            if (data[i] == 1)
            {
                cont++;
            }
        }
    }

    printf("The sender DATA: ");
    for (int i = data_len + (data_len / m) - 1; i >= 0; i--)
    {
        printf("%d", data[i]);
    }

    int redata[data_len + (data_len / m)], flag = 0;
    cont = 0;
    printf("\nEnter receiver DATA: ");
    for (int i = data_len + (data_len / m) - 1; i >= 0; i--)
    {

        scanf("%d", &redata[i]);
        if (i % (m + 1) == 0)
        {
            if (cont % 2 == 0 && redata[i] != 0)
            {
                flag = 1;
            }

            if (cont % 2 != 0 && redata[i] != 1)
            {
                flag = 1;
            }
            cont = 0;
        }
        else
        {
            if (data[i] == 1)
            {
                cont++;
            }
        }
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