#include <stdio.h>
#include <math.h>

int main()
{
    while (1)
    {
        printf("\n\n1. VRC");
        printf("\n2. LRC");
        printf("\n3. CRC");
        printf("\n4. checksum");
        printf("\n5. hamming");
        printf("\n6. Exit");
        printf("\nSelect option: ");
        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
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
            break;
        }

        case 2:
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

            int data[data_len + m];
            printf("Enter DATA: ");
            for (int i = data_len + m - 1; i >= m; i--)
            {
                scanf("%d", &data[i]);
            }

            int cont = 0;
            for (int i = data_len + m - 1; i >= data_len; i--)
            {
                int j;
                for (j = i; j > i % m; j -= m)
                {
                    if (data[j] == 1)
                    {
                        cont++;
                    }
                }

                // even parity
                if (cont % 2 == 0)
                {
                    data[j] = 0;
                }
                else
                {
                    data[j] = 1;
                }
                cont = 0;
            }

            printf("The sender DATA: ");
            for (int i = data_len + m - 1; i >= 0; i--)
            {
                printf("%d", data[i]);
            }

            int redata[data_len + m];
            printf("\nEnter receiver DATA: ");
            for (int i = data_len + m - 1; i >= 0; i--)
            {
                scanf("%d", &redata[i]);
            }

            int flag = 0;
            cont = 0;
            for (int i = data_len + m - 1; i >= data_len; i--)
            {
                int j;
                for (j = i; j > i % m; j -= m)
                {
                    if (redata[j] == 1)
                    {
                        cont++;
                    }
                }

                // even parity
                if (cont % 2 == 0 && redata[j] != 0)
                {
                    flag = 1;
                }

                if (cont % 2 != 0 && redata[j] != 1)
                {
                    flag = 1;
                }
                cont = 0;
            }

            if (flag == 1)
            {
                printf("Error");
            }
            else
            {
                printf("No Error");
            }

            break;
        }

        case 3:
        {
            int data_len, key_len;

            printf("Enter length of the DATA: ");
            scanf("%d", &data_len);
            printf("Enter length of the KEY: ");
            scanf("%d", &key_len);

            if (data_len < key_len)
            {
                return 0;
            }

            int key[key_len], data[data_len], apdata[data_len + key_len - 1];
            printf("Enter DATA: ");
            for (int i = data_len - 1; i >= 0; i--)
            {
                scanf("%d", &data[i]);
                apdata[i + key_len - 1] = data[i];
            }
            printf("Enter KEY: ");
            for (int i = key_len - 1; i >= 0; i--)
            {
                scanf("%d", &key[i]);
                if (i < key_len - 1)
                {
                    // The binary data is first augmented by adding
                    // k - 1 zeros in the end of the data
                    apdata[i] = 0;
                }
            }

            // Use modulo - 2 binary division to divide binary data by the key
            // and store remainder of division.
            for (int i = data_len + key_len - 2; i >= 3; i--)
            {
                if (apdata[i] == 1)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        apdata[i - j] ^= key[3 - j];
                    }
                }
            }

            // Append the remainder at the end of the data to
            // form the encoded data and send the same
            printf("The encoded DATA: ");
            for (int i = data_len + key_len - 2; i >= 0; i--)
            {
                if (i > key_len - 1)
                {
                    apdata[i] = data[i - key_len + 1];
                }
                printf("%d", apdata[i]);
            }

            int redata[data_len + key_len - 1];
            printf("\nEnter receiver DATA: ");
            for (int i = data_len + key_len - 2; i >= 0; i--)
            {
                scanf("%d", &redata[i]);
            }

            // Perform modulo - 2 division to the receiver DATA
            for (int i = data_len + key_len - 2; i >= 3; i--)
            {
                if (redata[i] == 1)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        redata[i - j] ^= key[3 - j];
                    }
                }
            }

            // if the remainder is 0, then there are no errors.
            for (int i = 0; i < data_len + key_len - 1; i++)
            {
                if (redata[i] != 0)
                {
                    printf("\nRejected");
                    break;
                }
            }

            printf("\nAccepted");
            break;
        }

        case 4:
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
            break;
        }

        case 5:
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
                    }
                    for (int j = 3 * (i + 1); j <= sdata_len; j += 2 * (i + 1))
                    {
                        for (int k = 0; k < i + 1; k++)
                        {
                            if ((j - 1 + k) < sdata_len)
                            {
                                value ^= sdata[j - 1 + k];
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
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            printf("Enter proper input");
            // return 0;
        }
        }
    }
    return 0;
}