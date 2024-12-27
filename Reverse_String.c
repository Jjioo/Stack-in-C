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
printf("%c",S->T[i]);
}
}


Stack fill_Stack(char* text){
Stack stack;
initialise(&stack,strlen(text));

for(int i =0 ; text[i]!= '\0'; i++){

add(&stack,text[i]);

}
return stack;
}


void reverse(char* text){
Stack S = fill_Stack(text);
for(int i =0 ; text[i]!= '\0'; i++){
text[i] = pop(&S);

}
free_stack(&S);
}


  
int main(){
 char* String = (char*) malloc(100 * sizeof(char));
 if(String == NULL) {
 fprintf(stderr , "error \n"); return 1;
 }
 printf("enter a String : ");
 scanf("%[^\n]",String);
 printf("Before : %s\n" , String); 
 reverse(String); 
 printf("After  : %s\n" , String);
 free(String);

}
