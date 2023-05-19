// //Q:-GIVEN A CFG, DO RECURSIVE DESCENT PARSING 

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void fA();
// void fB();
// void fS();

// #define SIZE 10000
// char arr_str[SIZE], token;
// int i = 0;

// void get_token()
// {
//     i++;
//     token = arr_str[i];
// }

// void error(){
//     printf("\nString is NOT ACCEPTED\n");
//     exit(0);    
// }

// void fA()
// {
//     switch (token)
//     {
//     case 'b':
//         get_token();

//         if(token == 'a')
//             get_token();

//         else
//             error();

//         break;

//     case 'a':
//         fS();
//         fB();
//         break;
//     case 'c':
//         fS();
//         fB();
//         break;
    
//     default:
//         error();
//         break;
//     }
// }

// void fB()
// {
//     switch (token)
//     {
//         case 'b':
//             get_token();
//             fA();
//             break;
        
//         case 'a':
//             fS();
//             break;
        
//         case 'c':
//             fS();
//             break;
        
//         default:
//             error();
//             break;
//     }
// }

// void fS()
// {
//     switch (token)
//     {
//     case 'a':
//         get_token();
//         fA();
//         fS();
//         break;
    
//     case 'c':
//         get_token();
//         break;

//     default:
//         break;
//     }
// }

// int main()
// {
//     printf("Enter the string : ");

//     fgets(arr_str, SIZE, stdin);
//     token = arr_str[0];

//     fS();

//     if(token == '$')
//         printf("\nString is ACCEPTED\n");
    
//     else   
//         error();


//     return 0;
// }

#include <stdio.h>
#include <string.h>
int E(), Edash(), T(), Tdash(), F();
char *ip;
char string[50];
int main()
{
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");

    if (E() && ip == "\0")
    {
        printf("\n--------------------------------\n");
        printf("\n String is successfully parsed\n");
    }
    else
    {
        printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
    }
}
int E()
{
    printf("%s\tE->TE' \n", ip);
    if (T())
    {
        if (Edash())
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
int Edash()
{
    if (*ip == '+')
    {
        printf("%s\tE'->+TE' \n", ip);
        ip++;
        if (T())
        {
            if (Edash())
            {
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        printf("%s\tE'->^ \n", ip);
        return 1;
    }
}
int T()
{
    printf("%s\tT->FT' \n", ip);
    if (F())
    {

        if (Tdash())
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
int Tdash()
{
    if (*ip == '*')
    {
        printf("%s\tT'->*FT' \n", ip);
        ip++;
        if (F())
        {
            if (Tdash())
            {
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        printf("%s\tT'->^ \n", ip);
        return 1;
    }
}
int F()
{
    if (*ip == '(')
    {
        printf("%s\tF->(E) \n", ip);
        ip++;
        if (E())
        {
            if (*ip == ')')
            {
                ip++;
                return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }

    else if (*ip == 'i')
    {
        ip++;
        printf("%s\tF->id \n", ip);
        return 1;
    }
    else
        return 0;
}
