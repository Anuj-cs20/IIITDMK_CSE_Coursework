#include <stdio.h>

int main()
{
    int n;
    printf("Enter Number of processes: ");
    scanf("%d", &n);

    int tq;
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int cs;
    printf("Enter context switch time: ");
    scanf("%d", &cs);

    int pid[n], at[n], bt[n], btl[n], ct[n], tat[n], wt[n], rt[n], rq[1000];
    for (int i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("Enter arrival time of %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of %d: ", i + 1);
        scanf("%d", &bt[i]);
        btl[i] = bt[i];
    }

    // Bubble sort
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                tmp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = tmp;

                tmp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = tmp;

                tmp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = tmp;

                tmp = btl[j];
                btl[j] = btl[j + 1];
                btl[j + 1] = tmp;
            }
        }
    }

    int time = 0, ind = 0, count = 0;
    int flag, ptime = 0, tat_sum = 0, wt_sum = 0, rt_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (at[i] <= time)
        {
            rq[ind++] = i;
        }
    }

    while (ind == 0)
    {
        ptime = time;
        time += tq;
        for (int j = 0; j < n; j++)
        {
            if (at[j] > ptime && at[j] <= time && btl[j] != 0)
            {
                rq[ind++] = j;
            }
        }
    }

    int start_time[n];
    for (int i = 0; i < n; i++)
    {
        start_time[i] = -1;
    }

    printf("\nReady Queue: \n");
    for (int i = 0; i < ind; i++)
    {
        for (int k = i; k < ind; k++)
        {
            printf("p%d ", rq[k] + 1);
        }
        printf("\n");

        if (start_time[rq[i]] == -1)
        {
            start_time[rq[i]] = time;
        }

        if (btl[rq[i]] <= tq)
        {
            time += btl[rq[i]];
            btl[rq[i]] = 0;
            ct[rq[i]] = time;
            tat[rq[i]] = ct[rq[i]] - at[rq[i]];
            wt[rq[i]] = tat[rq[i]] - bt[rq[i]];
            rt[rq[i]] = start_time[rq[i]] - at[rq[i]];

            tat_sum += tat[rq[i]];
            wt_sum += wt[rq[i]];
            rt_sum += rt[rq[i]];
        }
        else
        {
            time += tq;
            btl[rq[i]] -= tq;
        }

        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (at[j] > ptime && at[j] <= time && btl[j] != 0)
            {
                rq[ind++] = j;
            }
            if (btl[j] != 0)
            {
                flag = 1;
            }
        }

        if (btl[rq[i]] != 0)
        {
            rq[ind++] = rq[i];
            flag = 0;
        }

        while (i + 1 == ind && flag == 1)
        {
            ptime = time;
            time += tq;
            for (int j = 0; j < n; j++)
            {
                if (at[j] > ptime && at[j] <= time && btl[j] != 0)
                {
                    rq[ind++] = j;
                }
            }
        }

        ptime = time;
        if (rq[i] != rq[i + 1] && i + 1 != ind)
        {
            time += cs;
            count++;
        }
    }

    printf("\nRound Robin with Context Switch\n");
    printf("pid\tat\tbt\tct\ttat\twt\trt\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround time: %f", (float)tat_sum / n);
    printf("\nAverage Waiting time: %f", (float)wt_sum / n);
    printf("\nAverage Response time: %f", (float)rt_sum / n);
    printf("\nNo. of Context Switching: %d", count);
    return 0;
}