// Q: Given a file name, Write a C program to take it as an argument to identify the unique tokens and count the number of times each unique token occurred in the given file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_VALUE_SIZE 127
#define MAX_TYPE_SIZE 31
#define MAX_TOKENS 1023

typedef struct
{
	char value[MAX_VALUE_SIZE];
	char type[MAX_TYPE_SIZE];
	int count;
} Token;
Token token_default = (Token){.count = 0};

int uniqueTokenCount = 0;
int operators = 0, specialCharacters = 0, keywords = 0, constants = 0, strings = 0, identifiers = 0;

void addTokenToArray(Token *tokens, Token token);
int isUniqueToken(Token *tokens, Token token);
void printUniqueTokens(Token *tokens);

bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
		ch == '"' || ch == '\'')
		return (true);
	return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '=' || ch == '&' || ch == '|' || ch == '!' || ch == '^')
		return (true);
	return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool isValidIdentifier(char *str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
		return (false);
	return (true);
}

// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char *str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") ||
		!strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
		return (true);
	return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char *str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}
	return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char *str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}

bool isSpecialCharacter(char ch)
{
	if (ch == '"' || ch == '\'' || ch == '{' || ch == '}' ||
		ch == '[' || ch == ']' || ch == '(' || ch == ')' ||
		ch == '#' || ch == ',' || ch == ':' || ch == ';')
	{
		return true;
	}
	return false;
}

char *subString(char *str, int left, int right)
{
	int i;
	char *subStr = (char *)malloc(
		sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}

void tokenize(char *str, Token *tokens)
{
	int left = 0, right = 0;
	int len = strlen(str);
	int state = 0;
	int single = 1;
	int stringStart = 0;
	int stringEnded = 0;
	char *token;

	while (right <= len && left <= right)
	{
		if (!isDelimiter(str[right]))
		{
			right++;
		}
		else
		{
			if (left == right)
			{
				if (isOperator(str[right + 1]))
				{
					if (isOperator(str[right]))
					{
						right += 2;
						token = subString(str, left, right - 1);
						// printf("two ops token : %s\n", token);
						single = 0;
						left = right;
					}
					else
					{
						token = &str[right];
						right++;
						left = right;
						single = 1;
					}
				}
				else
				{
					token = &str[right];
					right++;
					left = right;
					single = 1;
				}
			}
			else
			{
				if (stringStart == 0)
				{
					token = subString(str, left, right - 1);
				}
				else
				{
					while (str[right] != '"' && str[right] != '\'')
					{
						right++;
					}
					token = subString(str, left, right - 1);
					// printf("token retrieval: %s\n", token);
					state = 6;
				}
				left = right;
				single = 0;
			}

			char ch;
			int i = 0;
			int dontStop = 1;

			// TRANSITION STATES
			while (dontStop)
			{
				switch (state)
				{
				case 0:
				{
					ch = token[i];
					i++;
					if (isalpha(ch))
					{
						state = 1;
						break;
					}
					else if (isdigit(ch))
					{
						state = 2;
						break;
					}
					else if (isOperator(ch))
					{
						state = 4;
						break;
					}
					else
					{
						state = 5;
						break;
					}
				}
				break;

				// KEYWORDS and IDENTIFIERS
				case 1:
				{
					ch = token[i];
					i++;
					if (isalpha(ch) || isdigit(ch))
					{
						state = 1;
						break;
					}
					else if (isKeyword(token))
					{
						Token currentToken = token_default;
						char type[] = "KEYWORD";
						strcpy(currentToken.value, token);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
						keywords++;
						dontStop = 0;
						break;
					}
					else if (ch != ' ')
					{
						if (!single)
						{
							Token currentToken = token_default;
							char type[] = "IDENTIFIER";
							strcpy(currentToken.value, token);
							strcpy(currentToken.type, type);
							addTokenToArray(tokens, currentToken);
						}
						else
						{
							char current[2];
							current[0] = token[0];
							current[1] = '\0';
							Token currentToken = token_default;
							char type[] = "IDENTIFIER";
							strcpy(currentToken.value, current);
							strcpy(currentToken.type, type);
							addTokenToArray(tokens, currentToken);
						}
						identifiers++;
						dontStop = 0;
						break;
					}
					else
					{
						dontStop = 0;
					}
				}
				break;

				// For INTEGERS
				case 2:
				{
					ch = token[i];
					i++;
					if (isdigit(ch))
					{
						state = 2;
						break;
					}
					else if (ch == '.')
					{
						state = 3;
						break;
					}
					else if (ch == 'u' || ch == 'U' || ch == 'I' || ch == 'L')
					{
						if (!single)
						{
							Token currentToken = token_default;
							char type[] = "INTEGER CONSTANT";
							strcpy(currentToken.value, token);
							strcpy(currentToken.type, type);
							addTokenToArray(tokens, currentToken);
						}
						else
						{
							char current[2];
							current[0] = token[0];
							current[1] = '\0';
							Token currentToken = token_default;
							char type[] = "INTEGER CONSTANT";
							strcpy(currentToken.value, current);
							strcpy(currentToken.type, type);
							addTokenToArray(tokens, currentToken);
						}
						constants++;
						dontStop = 0;
						break;
					}
					else
					{
						if (!single)
						{
							Token currentToken = token_default;
							char type[] = "INTEGER CONSTANT";
							strcpy(currentToken.value, token);
							strcpy(currentToken.type, type);
							addTokenToArray(tokens, currentToken);
						}
						else
						{
							char current[2];
							current[0] = token[0];
							current[1] = '\0';
							Token currentToken = token_default;
							char type[] = "INTEGER CONSTANT";
							strcpy(currentToken.value, current);
							strcpy(currentToken.type, type);
							addTokenToArray(tokens, currentToken);
						}
						constants++;
						dontStop = 0;
						break;
					}
				}
				break;

				// For DECIMALS
				case 3:
				{
					ch = token[i];
					i++;
					if (isdigit(ch))
					{
						state = 3;
						break;
					}
					else
					{
						Token currentToken = token_default;
						char type[] = "DECIMAL CONSTANT";
						strcpy(currentToken.value, token);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
						constants++;
						dontStop = 0;
						break;
					}
				}

				// For OPERATORS
				case 4:
				{
					ch = token[i];
					i++;
					char temp = token[i];
					if (isOperator(ch))
					{
						Token currentToken = token_default;
						char type[] = "OPERATOR";
						strcpy(currentToken.value, token);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
					}
					else
					{
						char current[2];
						current[0] = token[0];
						current[1] = '\0';
						Token currentToken = token_default;
						char type[] = "OPERATOR";
						strcpy(currentToken.value, current);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
					}
					operators++;
					dontStop = 0;
					break;
				}
				break;

				// For SPECIAL CHARACTERS
				case 5:
				{
					if (ch == '"' || ch == '\'')
					{
						state = 6;
						break;
					}
					else if (ch != ' ')
					{
						char current[2];
						current[0] = token[0];
						current[1] = '\0';
						Token currentToken = token_default;
						char type[] = "SPECIAL CHARACTER";
						strcpy(currentToken.value, current);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
						specialCharacters++;
						dontStop = 0;
						break;
					}
					else
					{
						dontStop = 0;
						break;
					}
				}
				break;

				// For STRINGS
				case 6:
				{
					if (stringStart)
					{
						Token currentToken = token_default;
						char type[] = "STRING";
						// printf("string yes: %s\n", token);
						strcpy(currentToken.value, token);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
						strings++;
						stringStart = 0;
						stringEnded = 1;
						dontStop = 0;
						break;
					}
					else if (ch == '"' || ch == '\'')
					{
						char current[2];
						current[0] = ch;
						current[1] = '\0';
						// printf("string no: %s\n", token);
						Token currentToken = token_default;
						char type[] = "SPECIAL CHARACTER";
						strcpy(currentToken.value, current);
						strcpy(currentToken.type, type);
						addTokenToArray(tokens, currentToken);
						specialCharacters++;
						if (stringEnded == 0)
						{
							stringStart = 1;
						}
						else
						{
							stringStart = 0;
							stringEnded = 0;
						}
						dontStop = 0;
						break;
					}
				}
				}
			}
		}

		// After concluding change state to 0
		state = 0;
	}
	return;
}

void removeUnnecessary(FILE *fpInput, FILE *fpOutput)
{
	char ch, current, previous;
	int redundantFlag = 0;
	ch = fgetc(fpInput);
	previous = '\n';
	current = ch;
	while (ch != EOF)
	{
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
		{
			if (redundantFlag == 0)
			{
				fputc(ch, fpOutput);
				redundantFlag = 1;
			}
			ch = fgetc(fpInput);
		}
		else
		{
			redundantFlag = 0;
			if (ch == '/')
			{
				ch = fgetc(fpInput);
				if (ch == '/')
				{
					while (ch != '\n')
					{
						ch = fgetc(fpInput);
					}
				}
				else if (ch == '*')
				{
					previous = fgetc(fpInput);
					current = fgetc(fpInput);
					int temp = 0;
					if (current == '/' && previous == '*')
					{
						temp = 1;
					}
					while (temp != 1)
					{
						previous = current;
						current = fgetc(fpInput);
						if (current == '/' && previous == '*')
						{
							temp = 1;
						}
					}
					ch = fgetc(fpInput);
				}
				else
				{
					fputc(ch, fpOutput);
				}
				ch = fgetc(fpInput);
			}
			else if (ch == '#')
			{
				if (previous == '\n')
				{
					while (ch != '\n')
					{
						ch = fgetc(fpInput);
					}
				}
				redundantFlag = 1;
			}
			else
			{
				fputc(ch, fpOutput);
				ch = fgetc(fpInput);
			}
		}
		previous = current;
		current = ch;
	}
}

int main(int argc, char **argv)
{
	// if (argc != 2)
	// {
	// 	printf("Please enter the file name as an argument[only one].\n");
	// 	exit(1);
	// }
	FILE *fpInput, *fpOutput;
	fpInput = fopen("dummy.c", "r");
	fpOutput = fopen("output.c", "w");
	Token tokens[MAX_TOKENS] = {token_default};
	// To remove redundant spaces, lines, comments and file directives.
	removeUnnecessary(fpInput, fpOutput);
	fclose(fpInput);
	fclose(fpOutput);
	FILE *fp = fopen("output.c", "r");
	char chunk[128];
	while (fgets(chunk, sizeof(chunk), fp) != NULL)
	{
		tokenize(chunk, tokens);
	}
	printUniqueTokens(tokens);
	return 0;
}

void addTokenToArray(Token *tokens, Token token)
{
	int index = isUniqueToken(tokens, token);
	if (index == -1)
	{
		token.count = 1;
		tokens[uniqueTokenCount] = token;
		uniqueTokenCount += 1;
	}
	else
	{
		tokens[index].count += 1;
	}
}

int isUniqueToken(Token *tokens, Token token)
{
	for (int i = 0; i < uniqueTokenCount; i++)
	{
		int result = strcmp(tokens[i].value, token.value);
		if (result == 0)
			return i;
	}
	return -1;
}

void printUniqueTokens(Token *tokens)
{
	printf("\n--------------------------------------------------------\n\n");
	for (int i = 0; i < uniqueTokenCount; i++)
	{
		printf("'\033[1;34m%s\033[0m' - token, '\033[0;32m%s\033[0m' - type : '\033[1;31m%d\033[0m' - count\n", tokens[i].value, tokens[i].type, tokens[i].count);
	}
	printf("\n--------------------------------------------------------\n\n");
}