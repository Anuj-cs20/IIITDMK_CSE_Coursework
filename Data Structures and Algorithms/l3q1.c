// 1) Encryption and Decryption using Matrix: Dynamically allocate a matrix with row and
//    column values as user input. Assign random values to the matrix elements. 
//    For encryption, WAP to increase the boundary element values of the matrix by the 
//    corresponding row number, and decrease the non-boundary elements by the 
//    corresponding (row+column) number. Also, write the corresponding decryption algorithm. 
//    What would be complexity of both the encryption and decryption algorithms? 
//    Please state the reason. [Wite on a white paper and submit with the assignment PDF file]
// cs20b1100 K.Anuj
// Complexity: n^2
#include <stdio.h>
#include <stdlib.h>
void Encry(int *a, int x, int y)
{
    for (size_t i = 0; i < x; ++i)
    {
        for (size_t j = 0; j < y; ++j)
        {
            if ((i > 0 && i < x - 1) && (j > 0 && j < y - 1))
            {
                a[y * i + j] += (i + j);
            }
            else
            {
                a[y * i + j] += i;
            }
        }
    }
}
void Decry(int *b, int u, int v)
{
    for (size_t i = 0; i < u; ++i)
    {
        for (size_t j = 0; j < v; ++j)
        {
            if ((i > 0 && i < u - 1) && (j > 0 && j < v - 1))
            {
                b[v * i + j] -= (i + j);
            }
            else
            {
                b[v * i + j] -= i;
            }
        }
    }
}
void Matrix(int *c, int a, int b)
{
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            printf("%d\t", c[b * i + j]);
        }
        puts("");
    }
    puts("");
}
int main()
{
    int rows, columns;
    puts("enter number of Rows and Columns");
    scanf("%d %d", &rows, &columns);
    int *arr = (int *)malloc(rows * columns * sizeof(int));
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            *(arr + columns * i + j) = rand() % 10;
        }
    }
    puts("");
    Matrix(arr, rows, columns);
    Encry(arr, rows, columns);
    Matrix(arr, rows, columns);
    Decry(arr, rows, columns);
    Matrix(arr, rows, columns);
    free(arr);
    return 0;
}