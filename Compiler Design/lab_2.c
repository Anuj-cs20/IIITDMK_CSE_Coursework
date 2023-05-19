/*
    2. Write a simple C code to remove spaces and
    new line enter characters and comment lines of a given input C program.
    Input: A text file with a C program
    Output: A text file of the above C program without
    any space between words and the whole program is in a single line.
    All comments to be removed from the input.
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

    int flag = 0, flag1 = 0;
    do
    {

        if (flag == 2 && ch == '*')
        {
            do
            {
                ch = fgetc(ptr);
                if (ch == '*')
                {
                    ch = fgetc(ptr);
                    if (ch == '/')
                    {
                        flag = 0;
                    }
                }

            } while (ch != EOF && flag != 0);
        }

        if (flag == 2)
        {
            do
            {
                ch = fgetc(ptr);
            } while (ch != EOF && ch != '\n');
            flag = 0;
        }

        ch = fgetc(ptr);
        if (flag1 == 0 && (ch == '/' || (ch == '*' && flag == 1)))
        {
            flag++;
        }
        else if (ch != ' ' && ch != '\n')
        {
            fprintf(ptr1, "%c", ch);
        }

        if (ch == '"')
        {
            if (flag1 == 0)
            {
                flag1 = 1;
            }
            else
            {
                flag1 = 0;
            }
        }

    } while (ch != EOF);

    fclose(ptr);
    return 0;
}