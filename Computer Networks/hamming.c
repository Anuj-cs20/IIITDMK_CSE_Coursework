#include <stdio.h>
#include <math.h>

int main()
{
    int data_len;
    printf("Enter data length: ");
    scanf("%d", &data_len);

    int parity_len = ceil(log2f(data_len)) + 1;
    printf("Parity length: %d\n", parity_len);

    int opt, parity;
    printf("\n1. EVEN parity");
    printf("\n2. ODD parity");
    printf("\nEnter a option: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
        parity = 0;
        break;

    case 2:
        parity = 1;
        break;

    default:
        parity = 0;
        printf("default EVEN parity");
        break;
    }

    int data[data_len];
    printf("Enter data: ");
    for (int i = data_len - 1; i >= 0; i--)
    {
        scanf("%d", &data[i]);
    }

    int sdata_len = data_len + parity_len;
    int sdata[sdata_len], k = 1, j = 0;

    for (int i = 0; i < sdata_len; i++)
    {
        if (i + 1 == k)
        {
            sdata[i] = -1;
            k *= 2;
        }
        else
        {
            sdata[i] = data[j++];
        }
    }

    // printf("\nparity bits as -1: ");
    // for (int i = sdata_len - 1; i >= 0; i--)
    // {
    //     printf("%d", sdata[i]);
    // }
    // printf("\n");

    int value;
    for (int i = 0; i < sdata_len; i = 2 * (i + 1) - 1)
    {
        if (sdata[i] == -1)
        {
            value = 0;
            for (int k = 1; k < i + 1; k++)
            {
                if (i + k < sdata_len)
                {
                    value ^= sdata[i + k];
                }
                else
                {
                    break;
                }
            }
            for (int j = 3 * (i + 1); j <= sdata_len; j += 2 * (i + 1))
            {
                for (int k = 0; k < i + 1; k++)
                {
                    if ((j - 1 + k) < sdata_len)
                    {
                        value ^= sdata[j - 1 + k];
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (parity == 0)
            {
                sdata[i] = value;
            }
            else
            {
                sdata[i] = (value == 0) ? 1 : 0;
            }
        }
    }

    printf("Sender data: ");
    for (int i = sdata_len - 1; i >= 0; i--)
    {
        printf("%d", sdata[i]);
    }

    int rdata_len = sdata_len;
    int rdata[rdata_len];
    printf("\n\nEnter receiver data: ");
    for (int i = rdata_len - 1; i >= 0; i--)
    {
        scanf("%d", &rdata[i]);
    }

    int flag = 0;
    for (int i = 0; i < sdata_len; i = 2 * (i + 1) - 1)
    {
        value = 0;
        for (int j = i + 1; j <= sdata_len; j += 2 * (i + 1))
        {
            for (int k = 0; k < i + 1; k++)
            {
                if ((j - 1 + k) < sdata_len)
                {
                    value ^= rdata[j - 1 + k];
                }
                else
                {
                    break;
                }
            }
        }
        if (parity == 0)
        {
            if (value != 0)
            {
                flag = 1;
                break;
            }
        }
        else
        {
            if (value == 0)
            {
                flag = 1;
                break;
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