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

    int bpf;
    printf("Enter No. of bits for frame: ");
    scanf("%d", &bpf);

    int j = 0;
    int newdata[100];
    int i = 0;
    while (i < data_len)
    {
        if (j % bpf == 0 && data_len - i >= bpf)
        {
            newdata[j] = bpf;
        }
        else if (j % bpf == 0 && data_len - i < bpf)
        {
            newdata[j] = data_len - i + 1;
        }
        else
        {
            newdata[j] = data[i];
            i++;
        }
        j++;
    }

    printf("\nCharacter Count is stuffed before every frame: ");
    for (int i = 0; i < j; i++)
    {
        printf("%d", newdata[i]);
    }

    return 0;
}