/*
    A polynomial code is a linear code having a set of valid code words
    that comprises of polynomials divisible by a shorter fixed polynomial
    is known as generator polynomial.

    They are used for error detection and correction during the transmission
    of data as well as storage of data.

    Modulo 2 arithmetic is performed digit by digit on binary numbers.
    Each digit is considered independently from its neighbours.
    Numbers are not carried or borrowed on performing Addition or substraction

    Cyclic Redundancy Check and Modulo-2 Division

    
*/

#include <stdio.h>

int main()
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
            return 0;
        }
    }

    printf("\nAccepted");
    return 0;
}