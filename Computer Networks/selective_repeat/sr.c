#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of the data: ");
    scanf("%d", &n);

    // int arr[n];
    // printf("Enter Data: ");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    int sw;
    printf("Enter size of sliding window: ");
    scanf("%d", &sw);

    int transmition_time = 1, propagation_time = 2, time = 0;
    int RTT = 2 * propagation_time;
    int time_out_timer = 2 * RTT;
    int ptr = 0, ptr1 = sw;
    int acknowledgement[n];
    for (int i = 0; i < n; i++)
    {
        acknowledgement[i] = 0;
    }

    int i = 0;
    while (i < n)
    {
        printf("\n\n");
        for (int j = 0; j < sw; j++)
        {
            if (acknowledgement[i + j] == 0)
            {
                printf("\nSending Frame number %d, time %d, sequence number %d", i + j + 1, time, (i + j) % (sw + sw));
                time += transmition_time;
            }
        }

        int flag = 1;
        for (int j = 0; j < sw; j++)
        {
            if (acknowledgement[i + j] == 0)
            {
                acknowledgement[i + j] = rand() % 2;
                if (acknowledgement[i + j] == 0)
                {
                    flag = 0;
                }
                else
                {
                    printf("\nReceived Acknowledgement time %d, sequence number %d", time, (i + j) % (sw + sw));
                }
            }
        }

        if (flag)
        {
            time += RTT;
            i += sw;
        }
        else
        {
            for (int j = 0; j < sw; j++)
            {
                if (acknowledgement[i + j] == 0)
                {
                    i = i + j;
                    break;
                }
            }
            time += time_out_timer;
        }
    }

    return 0;
}
