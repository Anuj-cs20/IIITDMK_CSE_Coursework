#include <stdio.h>
int main()
{
    int data_len;
    printf("Enter No. of data bits: ");
    scanf("%d", &data_len);

    int data[data_len];
    printf("Enter data: ");
    for (int i = data_len - 1; i >= 0; i--)
    {
        scanf("%d", &data[i]);
    }

    int j = data_len, count = 0;
    int sdata[data_len + (data_len / 5)];
    for (int i = data_len + (data_len / 5) - 1; i >= 0; i--)
    {
        if (count == 5)
        {
            sdata[i] = 0;
            count = 0;
        }
        else
        {
            if (j == 0)
            {
                sdata[i] = -1;
                break;
            }

            sdata[i] = data[--j];

            if (data[j] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        }
    }

    printf("\nBit stuffed data(After 5 consecutive 1-bits, a 0-bit is stuffed): ");
    for (int i = data_len + (data_len / 5) - 1; i >= 0; i--)
    {
        if (sdata[i] == -1)
        {
            break;
        }
        else
        {
            printf("%d", sdata[i]);
        }
    }

    return 0;
}