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
    int acknowledgement;
    int i;
    
    while (ptr1 <= n)
    {
        for (i = ptr; i < ptr1; i++)
        {
            printf("\nSending Frame number %d, time %d, sequence number %d", i + 1, time, i % (sw + 1));
            time += transmition_time;
        }

        acknowledgement = rand() % 2;
        if (acknowledgement)
        {
            // consider transmition time and process time
            // are '0' for acknowledgement
            time += RTT;
            printf("\nReceived Acknowledgement time %d, sequence number %d\n", time, i % (sw + 1));

            ptr += sw;
            ptr1 += sw;
        }
        else
        {
            time += time_out_timer;
        }
    }
    while (ptr1 > n)
    {
        for (i = ptr; i < n; i++)
        {
            printf("\nSending Frame number %d, time %d, sequence number %d", i + 1, time, i % (sw + 1));
            time += transmition_time;
        }

        acknowledgement = rand() % 2;
        if (acknowledgement)
        {
            time += RTT;
            printf("\nReceived Acknowledgement time %d,  sequence number %d\n", time, i % (sw + 1));
            printf("\nTransmitted all data successfully");
            break;
        }
        else
        {
            time += time_out_timer;
        }
    }

    return 0;
}
