// 2)WAP to input the elements of a symmatric matrix as an array (dynamic memory allocation).
//   User should input the rank of a square matrix. Print the elements of the matrix.
//   What is the complexity of the algorithm? Please state the reason.
//   [Wite on a white paper and submitwith the assignment PDF file].
// cs20b1100 K.Anuj
// Complexity: n^2
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    puts("Enter the order of the square matrix:");
    scanf("%d", &n);
    int *array = (int *)malloc(n * n * sizeof(int));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            *(array + i * n + j) = rand() % 10;
            *(array + j * n + i) = *(array + i * n + j);
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf(" %d ", *(array + i * n + j));
        }
        printf("\n");
    }
    free(array);
    return 0;
}