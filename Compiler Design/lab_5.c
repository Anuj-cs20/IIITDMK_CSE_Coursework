#include <stdio.h>

int main()
{
    FILE *ptr;
    char ch;

    ptr = fopen("dummy.c", "r");

    if (NULL == ptr)
    {
        printf("file can't be opened \n");
    }

    char type[30];
    char token[30], value[30][30];
    int i = 0, r = 0, c = 0;

    do
    {
        ch = fgetc(ptr);
        if (ch == 'i')
        {
            ch = fgetc(ptr);
            if (ch == 'n')
            {
                ch = fgetc(ptr);
                if (ch == 't')
                {
                    do
                    {
                        ch = fgetc(ptr);
                        if (ch != ' ' && ch != ',' && ch != ';')
                        {
                            token[i] = ch;
                            type[i] = 'd';
                            i++;
                        }
                    } while (ch != ';');
                }
            }
        }

        if (ch == 'c')
        {
            ch = fgetc(ptr);
            if (ch == 'h')
            {
                ch = fgetc(ptr);
                if (ch == 'a')
                {
                    ch = fgetc(ptr);
                    if (ch == 'r')
                    {
                        do
                        {
                            ch = fgetc(ptr);
                            if (ch != ' ' && ch != ',' && ch != ';')
                            {
                                token[i] = ch;
                                type[i] = 'c';
                                i++;
                            }
                        } while (ch != ';');
                    }
                }
            }
        }

        if (ch == 'f')
        {
            ch = fgetc(ptr);
            if (ch == 'l')
            {
                ch = fgetc(ptr);
                if (ch == 'o')
                {
                    ch = fgetc(ptr);
                    if (ch == 'a')
                    {
                        ch = fgetc(ptr);
                        if (ch == 't')
                        {
                            do
                            {
                                ch = fgetc(ptr);
                                if (ch != ' ' && ch != ',' && ch != ';')
                                {
                                    token[i] = ch;
                                    type[i] = 'f';
                                    i++;
                                }
                            } while (ch != ';');
                        }
                    }
                }
            }
        }

        if (ch != ' ' && ch != '\n')
        {
            for (int j = 0; j < i; j++)
            {
                if (ch == token[j])
                {
                    do
                    {
                        ch = fgetc(ptr);
                        if (ch != ' ' && ch != '=' && ch != ';')
                        {
                            value[j][c] = ch;
                            c++;
                        }
                    } while (ch != ';');
                    value[j][c] = '\0';
                    c = 0;
                }
            }
        }

    } while (ch != EOF);

    printf("\nToken\tType\tValue\n");
    for (int j = 0; j < i; j++)
    {

        printf("%c", token[j]);

        if (type[j] == 'd')
        {
            printf("\tint\t");
        }
        else if (type[j] == 'c')
        {
            printf("\tchar\t");
        }
        else
        {
            printf("\tfloat\t");
        }

        int k = 0;
        while (value[j][k] != '\0')
        {
            printf("%c", value[j][k]);
            k++;
        }
        printf("\n");
    }

    return 0;
}