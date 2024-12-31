#include <stdio.h>
#include <stdlib.h>

typedef struct {// Queue
   int* T;
   int head,tail,size;
}queue;

typedef struct{//Stack
int* T;
int size;
int index_top;
}Stack;

void initialise(queue* S, int s){
  S->T = (int*) malloc(s * sizeof(int));
  S->size = s;
  S->head = -1;
  S->tail = -1;
}

int empty(queue* q){
 return q->head == -1;
}

int full(queue* q){
 return q->tail == q->size-1;
}

void add(queue* q , int e){
	if(full(q)) return;
	if(empty(q)) q->head++; 
	q->tail ++;
	q->T[q->tail] = e;
}

int pop(queue* q){
	if(empty(q)) return -1;
	if(q->T == NULL) return -1;
	int first  = q->T[q->head];
	if(q->head == q->tail){
		q->head = q->tail = -1;
	}
	else {
		q->head ++;
	}
	return first;
	
}

void affichage(queue* q){
	if(empty(q)) return ;
	if(q->T == NULL) return ;
	
	for(int i = q->head ; i<=q->tail;i++){
		printf("%d->%d \n", i,q->T[i]);
		
	}
}




//Stack
void initialise_(Stack* S , int s){
  S->T = (int*) malloc(s * sizeof(int));
  S->size = s;
  S->index_top = -1;
}

int empty_(Stack* S){
 return S->index_top == -1;
}

int full_(Stack* S){
 return S->index_top == S->size -1;
}

void add_(Stack* S,int element){
 if(full_(S)) {
 printf("stack is full .\n"); return;
 }
S->index_top ++;
 S->T[S->index_top] = element;

}

void show_elements(Stack* S){
if(empty_(S)){
 printf("stack is empty .\n"); return;
 }

for(int i =0;i<=S->index_top;i++){
printf("%d-->%d\n",i,S->T[i]);
}}

int pop_( Stack* S){
 if(empty_(S)){
 printf("stack is empty .\n"); return -1;
 }
;
 return S->T[S->index_top --];
}

void reverse(Stack* S ,queue* q){
    
    while(q->tail >-1){
    add_(S , pop(q));}
    
    while(!empty_(S)){
    add(q,pop_(S));}
}
/* Recursive

void reverse(Stack* S ,queue* q){
 if(empty(q)){
    while (!empty_(S)) {
         add(q, pop_(S));
      }
      return;
 }   

add_(S, pop(q));
reverse(S ,q);

}

*/




int main() {
	queue q;
	initialise(&q , 5);
	
	Stack s;
	initialise_(&s , 5);
	add(&q ,1);
	add(&q ,2);
	add(&q ,3);
	
	
	printf("before : \n");
	affichage(&q);
	reverse(&s ,&q);
	free(s.T);
	s.T = NULL;
	printf("\n");
	printf("after : \n");
	affichage(&q);
    free(q.T);
	q.T = NULL;

	
	
    return 0;
}
