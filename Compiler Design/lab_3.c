/*
    3. Given a C program text file as input, write a C program and
    separate all Words and put all of them in an array.

    For example if the text file has the following line
    "My name = Ramesh+Suresh" then the output will be
    a[0]=My, a[1]=name, a[2]==, a[3]=Ramesh+Suresh

    You can print the array as output on the screen.
*/

#include <stdio.h>

int main()
{
    FILE *ptr;
    char ch;

    ptr = fopen("hello.c", "r");

    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }

    char arr[100][100];
    int row = 0, col = 0, flag = 0;
    do
    {
        ch = fgetc(ptr);
        if (ch != ' ' && ch != '\n')
        {
            arr[row][col] = ch;
            col++;
            flag = 0;
        }
        if (flag == 0 && (ch == ' ' || ch == '\n'))
        {
            arr[row][col] = '\0';
            col = 0;
            row++;
            flag = 1;
        }
    } while (ch != EOF);
    arr[row][col] = '\0';
    col = 0;
    row++;

    for (int i = 0; i < row; i++)
    {
        int j = 0;
        while (arr[i][j] != '\0')
        {
            printf("%c", arr[i][j]);
            j++;
        }
        printf("\n");
    }

    return 0;
}