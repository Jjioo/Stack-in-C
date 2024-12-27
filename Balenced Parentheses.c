#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct{
char* T;
int size;
int index_top;
}Stack;


void initialise(Stack* S , int s){
  S->T = (char*) malloc(s * sizeof(char));
  S->size = s;
  S->index_top = -1;
}

bool empty(Stack* S){
 return S->index_top == -1;
}

bool full(Stack* S){
 return S->index_top == S->size -1;
}

void add(Stack* S,char element){
 if(full(S)) {
 printf("stack is full .\n"); return;
 }

 S->T[++S->index_top] = element;

}

char pop(Stack* S){
 if(empty(S)){
 printf("stack is empty .\n"); return '\0';
 }
 return S->T[S->index_top--];
}

void free_stack(Stack* S){
 free(S->T);
 S->T = NULL;
}

void show_elements(Stack* S){
if(empty(S)){
 printf("stack is empty .\n"); return;
 }
for(int i =0;i<=S->index_top;i++){
printf("%d\n",S->T[i]);
}
}

int matching(char open , char close){
 return  (open=='(' && close == ')') ||
	 (open=='[' && close == ']') ||
	 (open=='{' && close == '}'); 
}

int isBalence(char* String){
Stack S;
initialise(&S ,strlen(String));
for(int i =0 ;String[i]!='\0';i++){
	char current = String[i];
	if(current == '(' || current == '[' || current == '{'){
	 add(&S,current);
	}
	else if(current == ')' || current == ']' || current == '}'){
	if(empty(&S) || !matching(pop(&S),current)){
	free_stack(&S);
	return 0;
	}
	}

}
int balenced =empty(&S);
free_stack(&S);
return balenced;

}





  
int main(){
 char String[10] ;
 printf("enter a String : ");
 scanf("%[^\n]",String);
 printf("the stack is %s balenced \n " ,isBalence(String)?"":"not ");

}
