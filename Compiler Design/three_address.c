//Q: Three address arithmetic operations generation

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 63

int t_count = 1;
int stack[MAX_SIZE];     
int top = -1;            

int is_empty() {
   if(top == -1)
      return 1;
   else
      return 0;
}
   
int is_full() {
   if(top == MAX_SIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;
   if(!is_empty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
			printf("Could not delete data, Stack is empty.\n");
			exit(1);
   }
	 return -1;
}

void push(int data) {
   if(!is_full()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
			exit(1);
   }
}

void mixed(char *expression, int i){
	int len = strlen(expression);
	int end = 0;
	if(i+4 == len){
		end = 1;
	}
	if(!end){
		if(is_empty()){
		printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
		printf("T%d = %c %c T%d\n", t_count, expression[i-1] , expression[i], t_count - 1);
		}else{
			int data = pop();
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("T%d = T%d %c T%d\n", t_count, data , expression[i], t_count - 1);
		}
	}else{
		if(is_empty()){
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("out = %c %c T%d\n", expression[i-1] , expression[i], t_count - 1);
		}else{
			int data = pop();
			printf("T%d = %c %c %c\n", t_count++, expression[i+1], expression[i+2], expression[i+3]);
			printf("out = T%d %c T%d\n",  data , expression[i], t_count - 1);
		}
	}
	push(t_count);
	t_count+=1;
}

void div_mul(char *expression, int i){
	int len = strlen(expression);
	int end = 0;
	if(i+2 == len){
		end = 1;
	}
	if(!end){
		if(is_empty()){
		printf("T%d = %c %c %c\n", t_count, expression[i-1], expression[i], expression[i+1]);
		}else{
			int data = pop();
			printf("T%d = T%d %c %c\n", t_count, data, expression[i], expression[i+1]);
		}
	}else{
		if(is_empty()){
		printf("out = %c %c %c\n", expression[i-1], expression[i], expression[i+1]);
		}else{
			int data = pop();
			printf("out = T%d %c %c\n", data, expression[i], expression[i+1]);
		}
	}
	push(t_count);
	t_count+=1;
}

void add_sub(char *expression, int i){
	int len = strlen(expression);
	int end = 0;
	if(i+2 == len){
		end = 1;
	}
	if(!end){
		if(is_empty()){
		printf("T%d = %c %c %c\n", t_count, expression[i-1], expression[i], expression[i+1]);
		}else{
			int data = pop();
			printf("T%d = T%d %c %c\n", t_count, data, expression[i], expression[i+1]);
		}
	}else{
		if(is_empty()){
		printf("out = %c %c %c\n", expression[i-1], expression[i], expression[i+1]);
		}else{
			int data = pop();
			printf("out = T%d %c %c\n", data, expression[i], expression[i+1]);
		}
	}
	push(t_count);
	t_count+=1;
}

int main()
{
	char expression[MAX_SIZE];
	printf("\nEnter the expression with arithmetic operator[without assignment]: ");
	scanf("%s", expression);
	int len = strlen(expression);
	for(int i = 0; i < len; i++){
		if(expression[i] == '+' || expression[i] == '-'){
			if(expression[i+2] == '*' || expression[i+2] == '/'){
				mixed(expression, i);
				i+=2;
			}else{
				add_sub(expression, i);
			}
		}else if(expression[i] == '*' || expression[i] == '/'){
			div_mul(expression, i);
		}
	}
	return 0;
}