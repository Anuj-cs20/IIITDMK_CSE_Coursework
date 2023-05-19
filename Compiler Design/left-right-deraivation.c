#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>

char str[100][100];
int countarr[100];
int n;
char str1[1000];


void debug2d(int n)
{
	for(int i=0;i<n;i++){
		printf("[%d] = [%s]\n",i,str[i]);
	}
}

void debug1d(int n)
{
	for(int i=0;i<n;i++){
		printf("[%d] = [%d]\n",i,countarr[i]);
	}
}

void add_string_at_index(char* string1, char* string2,int index)
{
	// string1 = original string , string2 = string to be added
	char temp[1000];
	int tempi = 0;
	temp[0] = '\0';
	for(int i = index+1;i<strlen(string1);i++){
		temp[tempi] = string1[i];
		temp[tempi+1] = '\0';
		tempi++;
	}
	tempi = index;
	for(int i=0;i<strlen(string2);i++){
		string1[tempi] = string2[i];
		string1[tempi+1] = '\0';
		tempi++;
	}
	for(int i=0;i<strlen(temp);i++){
		string1[tempi] = temp[i];
		string1[tempi+1] = '\0';
		tempi++;
	}
	// printf("\n------------------\nstring = %s\n---------------\n",string1);
}

int continue_parsing(char* ans){
	/*
		0 = stop parsing
		1 = continue parsing
		2 = string obtained
	*/

	int n = strlen(ans);
	// Check for captial letters
	if(n > strlen(str1)+3)return 0;
	else if(n == strlen(str1)){
		for(int i=0;i<n;i++){
			if(str1[i] != ans[i])return 1;
		}
		return 2; 
	}else{
		int leftptr = 0, rightptr = n-1;
		while(ans[leftptr] >= 91){
			if(str1[leftptr] != ans[leftptr])return 0;
			leftptr++;
		}
		int str1_rptr = strlen(str1) -1;
		while(ans[rightptr] >= 91 && rightptr >= 0){
			if(ans[rightptr] != str1[str1_rptr])return 0;
			rightptr--;
			str1_rptr--;
		}
		return 1;
	}
}

void printPath(char path[][1000],int path_index)
{
	printf("\nThe path is:  \n");
	for(int i=0;i<path_index;i++){
		printf("[%s]\n",path[i]);
	}
}

bool firstpath;
char fpath[1000][1000];
char lpath[1000][1000];
int findex;
int pindex;

void remove_epsilon(char cstr[]){
	printf("\nString = %s",cstr);
	for(int i=0;i<strlen(cstr);i++){
		if(cstr[i] == '#'){
			int j = i,k = i;
			while(true){
				cstr[k] = cstr[k+1];
				if(cstr[k] == '\0')break;
				k++;
			}
		}	
	}
	// printf("\nNew string = %s",cstr);
}

void derivation(char cstr[],char path[][1000],int path_index)
{
	// if(strlen(cstr) >= strlen(str1))return;
	remove_epsilon(cstr);
	int a = continue_parsing(cstr);
	// printf("\ncstr = %s | a = %d",cstr,a);
	if(a == 0)return;
	else if(a == 2){
		// printf("\n------------STRING OBTAINED!---------------\n");
		if(firstpath == true){
			findex = path_index;
			for(int i=0;i<path_index;i++){
				strcpy(fpath[i],path[i]);
			}
			firstpath = false;
		}
		// printf("\nThe string = %s",cstr);
		// printPath(path,path_index);
		for(int i=0;i<path_index;i++){
			strcpy(lpath[i],path[i]);
		}
		pindex = path_index;
	}

	// printf("\nThe string is:  %s",cstr);
	for(int i=0;i<strlen(cstr);i++){
		if(cstr[i] < 91 && cstr[i] > 64){
			char x = cstr[i];
			for(int j=0;j<n;j++){
				if(str[j][0] == x){
					int k = 3;
					char temp[1000];
					int ind = 0;
					temp[ind] = '\0';
					char ccstr[1000];
					strcpy(ccstr,cstr);
					while(str[j][k]!='\0'){
						// printf("\nTemp = %s | k = %d | str[j] = %s | j = %d | x = %c",temp,k,str[j],j,x);
						// printf("\ncstr = %s",cstr);
						if(str[j][k]=='|'){
							strcpy(ccstr,cstr);
							add_string_at_index(ccstr,temp,i);
							strcpy(path[path_index],ccstr);
							// printf("\nTemp = %s",temp);
							derivation(ccstr,path,path_index+1);
							ind = 0;
							temp[ind] = '\0';
							k++;
						}else{
							temp[ind] = str[j][k];
							temp[ind+1] = '\0';
							ind++;
							k++;
						}
						if(str[j][k] == '\0'){
							strcpy(ccstr,cstr);
							add_string_at_index(ccstr,temp,i);
							strcpy(path[path_index],ccstr);
							// printf("\nTemp = %s",temp);
							derivation(ccstr,path,path_index+1);

						}
					}
					break;
				}
			}
		}
	}
}

int main()
{
	printf("\nEnter the number of production rules:  ");
	scanf("%d",&n);
	printf("\n[Production rule input example:   S-aAS|c (Without spaces separated by '|')]\nNote: Please Enter production rule for a terminal in the line itself.\n");
	printf("\nRepresent S' as E, # and Epsilon");
	printf("\nInput the Non-Terminals in the following order:  E,S,(Other Non-Terminals)\n");
	for(int i=0;i<n;i++){
		printf("\nEnter the production rule:  ");
		scanf("%s",str[i]);
	}
	printf("\nEnter the string:  ");
	scanf("%s",str1);
	debug2d(n);
	memset(countarr,0,sizeof(countarr));
	for(int i=0;i<n;i++){
		int x = strlen(str[i]);
		for(int j=0;j<x;j++){
			if(str[i][j]=='|')countarr[i]++;
		}
		countarr[i]++;
	}
	debug1d(n);
	char new_str1[1000] = "S";char new_str2[1000] = "S";
	printf("\nnew_str1 = %s; new_str2 = %s\n",new_str1,new_str2);

	char path[1000][1000];
	int path_index = 0;

	firstpath = true;
	derivation(new_str1,path,path_index);

	if(firstpath == true){
		printf("\nThe string is rejected!");
		return 0;
	}

	remove_epsilon(fpath[findex-1]);

	printf("\nThe leftmost derivation : \n");
	for(int i=0;i<findex;i++){
		printf("[%s]\n",fpath[i]);
	}

	remove_epsilon(lpath[pindex-1]);
	printf("\nThe rightmost derivation:  \n");
	for(int i=0;i<pindex;i++){
		printf("[%s]\n",lpath[i]);
	}

	return 0;
}