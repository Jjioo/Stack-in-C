#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct{
int* T;
int size;
int index_top;
}Stack;


void initialise(Stack* S , int s){
  S->T = (int*) malloc(s * sizeof(int));
  S->size = s;
  S->index_top = -1;
}

bool empty(Stack* S){
 return S->index_top == -1;
}

bool full(Stack* S){
 return S->index_top == S->size -1;
}

void add(Stack* S,int element){
 if(full(S)) {
 printf("stack is full .\n"); return;
 }

 S->T[++S->index_top] = element;

}

int pop(Stack* S){
 if(empty(S)){
 printf("stack is empty .\n"); return -1;
 }


 return S->T[--S->index_top];
}

void free_stack(Stack* S){
 free(S->T);
 S->T = NULL;
}

bool contains(Stack* S , int element){
  bool exist = false;
  
  for(int i =0;i<S->index_top;i++){
	 if(S->T[i] ==element) exist = true;
  
  }
  return exist;

}

void show_elements(Stack* S){
if(empty(S)){
 printf("stack is empty .\n"); return;
 }
for(int i =0;i<=S->index_top;i++){
printf("%d\n",S->T[i]);

}


}

int peak(Stack* S){
return S->T[S->index_top];}


int get(Stack* S, int index){
        if(empty(S)) return 0;
        if(index>S->index_top || index<0) return 0;
        return S->T[index];


}

void set(Stack* S, int index,int value){
         if(empty(S)) return ;
        if(index>S->index_top || index<0) return ;

        S->T[index] = value;

}

void _size(Stack* S){
  if(empty(S)) return ;
  else {
  printf("size = %d\n", S->size);
  }

}
  
int main(){
 Stack stack;
 int size = 5;
 initialise(&stack , size);
 for(int i =1;i<=size;i++){
 add(&stack , i);
 }



 show_elements(&stack);
 printf("\n");
 // printf("%d",pop(&stack));
 // Pop an element
   // printf("Popped element: %d\n", pop(&stack));
//printf("peek is %d \n \n", peak(&stack)); 
// show_elements(&stack);
 //printf("element with index %d  is %d \n \n", 2, get(&stack,2));
 // set(&stack,4,999);
  //show_elements(&stack);
 _size(&stack);
 free_stack(&stack);
// printf("%d",full(&stack));

}
