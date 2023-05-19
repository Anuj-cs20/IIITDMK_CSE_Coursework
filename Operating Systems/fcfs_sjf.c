// K.Anuj CS20B1100

#include <stdio.h>

int main()
{
    int n;
    printf("Enter No. of Processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];
    int ct1[n], wt1[n], tat1[n];

    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Arrival Time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int tmp;
    float avg_wt = 0, avg_tat = 0;
    // Bubble Sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                tmp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = tmp;

                tmp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tmp;

                tmp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ct[i] = bt[i] + at[i];
        }
        else
        {
            if (ct[i - 1] < at[i])
            {
                ct[i] = bt[i] + at[i];
            }
            else
            {
                ct[i] = ct[i - 1] + bt[i];
            }
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nFirst Come First Serve technique\n");
    printf("pid\tat\tbt\tct\ttat\twt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    avg_wt /= n;
    avg_tat /= n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage turnaround Time: %f\n", avg_tat);

    float avg_wt1 = 0, avg_tat1 = 0;
    // Bubble Sort with extra conditions
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                tmp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = tmp;

                tmp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tmp;

                tmp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = tmp;
            }
            else if (at[j] == at[j + 1] && bt[j] > bt[j + 1])
            {
                tmp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = tmp;

                tmp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tmp;

                tmp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        // executing min job
        if (i == 0)
        {
            ct1[i] = bt[i] + at[i];
        }
        else
        {
            if (ct[i - 1] < at[i])
            {
                ct1[i] = bt[i] + at[i];
            }
            else
            {
                ct1[i] = ct1[i - 1] + bt[i];
            }
        }
        tat1[i] = ct1[i] - at[i];
        wt1[i] = tat1[i] - bt[i];

        avg_wt1 += wt1[i];
        avg_tat1 += tat1[i];

        // Finding min job which arrived with in the complete time of the previous process
        int minIndex = i + 1;
        for (int j = i + 1; j < n; j++)
        {
            if (at[j] <= ct1[i] && bt[minIndex] > bt[j])
            {
                minIndex = j;
            }
        }

        tmp = at[minIndex];
        at[minIndex] = at[i + 1];
        at[i + 1] = tmp;

        tmp = bt[minIndex];
        bt[minIndex] = bt[i + 1];
        bt[i + 1] = tmp;

        tmp = pid[minIndex];
        pid[minIndex] = pid[i + 1];
        pid[i + 1] = tmp;
    }

    printf("\nShortest Job First\n");
    printf("pid\tat\tbt\tct\ttat\twt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct1[i], tat1[i], wt1[i]);
    }
    avg_wt1 /= n;
    avg_tat1 /= n;
    printf("\nAverage Waiting Time: %f", avg_wt1);
    printf("\nAverage turnaround Time: %f\n", avg_tat1);

    printf("\nAccording to Average Waiting Time: ");
    if (avg_wt > avg_wt1)
    {
        printf("SJF is more efficient than FCFS");
    }
    else if (avg_wt < avg_wt1)
    {
        printf("FCFS is more efficient than SJF");
    }
    else
    {
        printf("FCFS is as efficient as SJF");
    }

    printf("\nAccording to Average turnaround Time: ");
    if (avg_tat > avg_tat1)
    {
        printf("SJF is more efficient than FCFS");
    }
    else if (avg_tat < avg_tat1)
    {
        printf("FCFS is more efficient than SJF");
    }
    else
    {
        printf("FCFS is as efficient as SJF");
    }

    printf("\nComplexity: FCFS O(n^2), SJF O(n^2)\nDue to bubble sort\nIf we use Quick Sort we get both as O(n*log(n))");
    return 0;
}