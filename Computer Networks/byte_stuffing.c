#include <stdio.h>
int main()
{
    int data_len;
    printf("Enter No. of data bits: ");
    scanf("%d", &data_len);

    int data[data_len];
    printf("Enter data: ");
    for (int i = 0; i < data_len; i++)
    {
        scanf("%d", &data[i]);
    }

    int esc_len;
    printf("Enter  escape character(ESC) length: ");
    scanf("%d", &esc_len);

    int esc[esc_len];
    printf("Enter ESC: ");
    for (int i = 0; i < esc_len; i++)
    {
        scanf("%d", &esc[i]);
    }

    int flag_len;
    printf("Enter  flag length: ");
    scanf("%d", &flag_len);

    int flag[flag_len];
    printf("Enter flag: ");
    for (int i = 0; i < flag_len; i++)
    {
        scanf("%d", &flag[i]);
    }

    int flag1 = 0, flag2 = 0, j = 0, k = 0, l = 0;
    int index[100];
    for (int i = 0; i < data_len; i++)
    {
        if (data[i] == flag[j])
        {
            flag1++;
            j++;
        }
        else
        {
            flag1 = 0;
            j = 0;
            if (data[i] == flag[j])
            {
                flag1++;
                j++;
            }
        }

        if (data[i] == esc[k])
        {
            flag2++;
            k++;
        }
        else
        {
            flag2 = 0;
            k = 0;
            if (data[i] == esc[k])
            {
                flag2++;
                k++;
            }
        }

        if (flag1 == flag_len)
        {
            index[l] = i - flag_len + 1;
            l++;
            flag1 = 0;
            j = 0;
            flag2 = 0;
            k = 0;
        }

        if (flag2 == esc_len)
        {
            index[l] = i - esc_len + 1;
            l++;
            flag1 = 0;
            j = 0;
            flag2 = 0;
            k = 0;
        }
    }

    printf("\nData after Byte stuffing: ");
    int newdata[data_len + (l * esc_len)], n = 0, l1 = 0;
    for (int i = 0; i < data_len; i++)
    {
        if (index[l1] == i && l1 < l)
        {
            l1++;
            // byte insertion index
            // printf("%d ", i);
            for (int e = 0; e < esc_len; e++)
            {
                newdata[n++] = esc[e];
            }
        }

        newdata[n++] = data[i];
    }

    printf("\n");
    for (int i = 0; i < data_len + (l * esc_len); i++)
    {
        printf("%d", newdata[i]);
    }

    return 0;
}