//Given an input string which is an assignment statement with arithmetic operations(DMAS- Division, Multiplication, Addition, Subtraction), write a C program to generate three address code by considering the following.

//Division and multiplication (DM) has same precedence.
//Addition and subtraction (AS )has same  precedence.
//But DM has high precedence over AS.

//Also consider left-to-right associativity which defines the order in which the operators of the same precedence will be evaluated in an expression.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 63

int flag = 1;
int stk[n];
int top = -1;

int stackEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int stackFull()
{
	if (top == n)
		return 1;
	else
		return 0;
}

int peek()
{
	return stk[top];
}

int pop()
{
	int temp;
	if (!stackEmpty())
	{
		temp = stk[top];
		top = top - 1;
		return temp;
	}

	else
	{
		printf("Could not delete temp, Stack is empty.\n");
		exit(1);
	}

	return -1;
}

void push(int temp)
{
	if (!stackFull())
	{
		top = top + 1;
		stk[top] = temp;
	}
	else
	{
		printf("Could not insert temp, Stack is full.\n");
		exit(1);
	}
}

void mulPrecedences(char *expression, int i)
{
	int len = strlen(expression);
	int check = 0;
	if (i + 4 == len)
	{
		check = 1;
	}

	if (!check)
	{
		if (stackEmpty())
		{
			printf("T%d = %c %c %c\n", flag++, expression[i + 1], expression[i + 2], expression[i + 3]);
			printf("T%d = %c %c T%d\n", flag, expression[i - 1], expression[i], flag - 1);
		}

		else
		{
			int temp = pop();
			printf("T%d = %c %c %c\n", flag++, expression[i + 1], expression[i + 2], expression[i + 3]);
			printf("T%d = T%d %c T%d\n", flag, temp, expression[i], flag - 1);
		}
	}

	else
	{
		if (stackEmpty())
		{
			printf("T%d = %c %c %c\n", flag++, expression[i + 1], expression[i + 2], expression[i + 3]);
			printf("out = %c %c T%d\n", expression[i - 1], expression[i], flag - 1);
		}

		else
		{
			int temp = pop();
			printf("T%d = %c %c %c\n", flag++, expression[i + 1], expression[i + 2], expression[i + 3]);
			printf("out = T%d %c T%d\n", temp, expression[i], flag - 1);
		}
	}

	push(flag);
	flag += 1;
}

void mulAnddiv(char *expression, int i)
{
	int len = strlen(expression);
	int check = 0;

	if (i + 2 == len)
	{
		check = 1;
	}

	if (!check)
	{
		if (stackEmpty())
		{
			printf("T%d = %c %c %c\n", flag, expression[i - 1], expression[i], expression[i + 1]);
		}

		else
		{
			int temp = pop();
			printf("T%d = T%d %c %c\n", flag, temp, expression[i], expression[i + 1]);
		}
	}

	else
	{
		if (stackEmpty())
		{
			printf("out = %c %c %c\n", expression[i - 1], expression[i], expression[i + 1]);
		}

		else
		{
			int temp = pop();
			printf("out = T%d %c %c\n", temp, expression[i], expression[i + 1]);
		}
	}

	push(flag);
	flag += 1;
}

void addAndsub(char *expression, int i)
{
	int len = strlen(expression);
	int check = 0;

	if (i + 2 == len)
	{
		check = 1;
	}

	if (!check)
	{
		if (stackEmpty())
		{
			printf("T%d = %c %c %c\n", flag, expression[i - 1], expression[i], expression[i + 1]);
		}

		else
		{
			int temp = pop();
			printf("T%d = T%d %c %c\n", flag, temp, expression[i], expression[i + 1]);
		}
	}

	else
	{
		if (stackEmpty())
		{
			printf("out = %c %c %c\n", expression[i - 1], expression[i], expression[i + 1]);
		}

		else
		{
			int temp = pop();
			printf("out = T%d %c %c\n", temp, expression[i], expression[i + 1]);
		}
	}

	push(flag);
	flag += 1;
}

int main()
{
	char expression[n];
	printf("\nEnter the expression without spaces ( ex. out=a+d+c+b ) =  : ");
	scanf("%s", expression);
	int len = strlen(expression);

	for (int i = 0; i < len; i++)
	{
		if (expression[i] == '+' || expression[i] == '-')
		{
			if (expression[i + 2] == '*' || expression[i + 2] == '/')
			{
				mulPrecedences(expression, i);
				i += 2;
			}

			else
			{
				addAndsub(expression, i);
			}
		}

		else if (expression[i] == '*' || expression[i] == '/')
		{
			mulAnddiv(expression, i);
		}
	}
	return 0;
}