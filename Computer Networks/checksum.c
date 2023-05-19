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

    int data[(data_len / m) + 1][m];
    printf("Enter DATA: ");
    for (int i = 0; i < (data_len / m); i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            scanf("%d", &data[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        data[(data_len / m)][i] = 0;
    }

    int flag = 0;
    for (int i = 0; i < (data_len / m); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (data[i][j] == 0 && data[(data_len / m)][j] == 0 && flag == 0)
            {
                data[(data_len / m)][j] = 0;
                flag = 0;
            }
            else if (data[i][j] == 0 && data[(data_len / m)][j] == 0 && flag == 1)
            {
                data[(data_len / m)][j] = 1;
                flag = 0;
            }
            else if (data[i][j] == 0 && data[(data_len / m)][j] == 1 && flag == 0)
            {
                data[(data_len / m)][j] = 1;
                flag = 0;
            }
            else if (data[i][j] == 0 && data[(data_len / m)][j] == 1 && flag == 1)
            {
                data[(data_len / m)][j] = 0;
                flag = 1;
            }
            else if (data[i][j] == 1 && data[(data_len / m)][j] == 0 && flag == 0)
            {
                data[(data_len / m)][j] = 1;
                flag = 0;
            }
            else if (data[i][j] == 1 && data[(data_len / m)][j] == 0 && flag == 1)
            {
                data[(data_len / m)][j] = 0;
                flag = 1;
            }
            else if (data[i][j] == 1 && data[(data_len / m)][j] == 1 && flag == 0)
            {
                data[(data_len / m)][j] = 0;
                flag = 1;
            }
            else if (data[i][j] == 1 && data[(data_len / m)][j] == 1 && flag == 1)
            {
                data[(data_len / m)][j] = 1;
                flag = 1;
            }
        }
        while (flag == 1)
        {
            if (data[(data_len / m)][0] == 0)
            {
                data[(data_len / m)][0] = 1;
                flag = 0;
            }
            else
            {
                data[(data_len / m)][0] = 0;
                flag = 1;
            }

            for (int j = 1; j < m; j++)
            {
                if (data[(data_len / m)][j] == 0 && flag == 0)
                {
                    data[(data_len / m)][j] = 0;
                    flag = 0;
                }
                else if (data[(data_len / m)][j] == 0 && flag == 1)
                {
                    data[(data_len / m)][j] = 1;
                    flag = 0;
                }
                else if (data[(data_len / m)][j] == 1 && flag == 0)
                {
                    data[(data_len / m)][j] = 1;
                    flag = 0;
                }
                else if (data[(data_len / m)][j] == 1 && flag == 1)
                {
                    data[(data_len / m)][j] = 0;
                    flag = 1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (data[(data_len / m)][i] == 0)
        {
            data[(data_len / m)][i] = 1;
        }
        else
        {
            data[(data_len / m)][i] = 0;
        }
    }

    printf("The sender DATA: ");
    for (int i = 0; i < (data_len / m) + 1; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            printf("%d", data[i][j]);
        }
        // printf("\n");
    }

    int redata[(data_len / m) + 1][m];
    printf("\nEnter receiver DATA: ");
    for (int i = 0; i < (data_len / m) + 1; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            scanf("%d", &redata[i][j]);
        }
    }

    flag = 0;
    for (int i = 0; i < (data_len / m); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (redata[i][j] == 0 && redata[(data_len / m)][j] == 0 && flag == 0)
            {
                redata[(data_len / m)][j] = 0;
                flag = 0;
            }
            else if (redata[i][j] == 0 && redata[(data_len / m)][j] == 0 && flag == 1)
            {
                redata[(data_len / m)][j] = 1;
                flag = 0;
            }
            else if (redata[i][j] == 0 && redata[(data_len / m)][j] == 1 && flag == 0)
            {
                redata[(data_len / m)][j] = 1;
                flag = 0;
            }
            else if (redata[i][j] == 0 && redata[(data_len / m)][j] == 1 && flag == 1)
            {
                redata[(data_len / m)][j] = 0;
                flag = 1;
            }
            else if (redata[i][j] == 1 && redata[(data_len / m)][j] == 0 && flag == 0)
            {
                redata[(data_len / m)][j] = 1;
                flag = 0;
            }
            else if (redata[i][j] == 1 && redata[(data_len / m)][j] == 0 && flag == 1)
            {
                redata[(data_len / m)][j] = 0;
                flag = 1;
            }
            else if (redata[i][j] == 1 && redata[(data_len / m)][j] == 1 && flag == 0)
            {
                redata[(data_len / m)][j] = 0;
                flag = 1;
            }
            else if (redata[i][j] == 1 && redata[(data_len / m)][j] == 1 && flag == 1)
            {
                redata[(data_len / m)][j] = 1;
                flag = 1;
            }
        }
        while (flag == 1)
        {
            if (redata[(data_len / m)][0] == 0)
            {
                redata[(data_len / m)][0] = 1;
                flag = 0;
            }
            else
            {
                redata[(data_len / m)][0] = 0;
                flag = 1;
            }

            for (int j = 1; j < m; j++)
            {
                if (redata[(data_len / m)][j] == 0 && flag == 0)
                {
                    redata[(data_len / m)][j] = 0;
                    flag = 0;
                }
                else if (redata[(data_len / m)][j] == 0 && flag == 1)
                {
                    redata[(data_len / m)][j] = 1;
                    flag = 0;
                }
                else if (redata[(data_len / m)][j] == 1 && flag == 0)
                {
                    redata[(data_len / m)][j] = 1;
                    flag = 0;
                }
                else if (redata[(data_len / m)][j] == 1 && flag == 1)
                {
                    redata[(data_len / m)][j] = 0;
                    flag = 1;
                }
            }
        }
    }

    flag = 0;
    for (int j = m - 1; j >= 0; j--)
    {
        if (redata[(data_len / m)][j] != 1)
        {
            flag = 1;
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