/*
    1. Write a simple C code to remove spaces and
    new line enter characters of a given input C program.
    Input : A text file with a C program
    Output : A text file of the above C program without any space
    between words and the whole program is in a single line.
*/

#include <stdio.h>

int main()
{
    FILE *ptr, *ptr1;
    char ch;

    ptr = fopen("hello.c", "r");
    ptr1 = fopen("hello1.c", "w");

    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }

    do
    {
        ch = fgetc(ptr);
        if (ch != ' ' && ch != '\n')
        {
            fprintf(ptr1, "%c", ch);
        }

    } while (ch != EOF);

    fclose(ptr);
    return 0;
}