#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* T;
    int head,tail,size;
}queue;


void inisialize(queue* q,int s){
    q->T = (int*) malloc(s * sizeof(int));
    q->size = s;
    q->head = -1;
    q->tail = -1;
}

int isEmpty(queue* q){
    return q->head == -1;
}
int isFull(queue* q){
    return q->tail == q->size-1;
}

void afficher(queue* q){
    if(q == NULL){printf("is empty \n"); return;}
    if(isEmpty(q)) {printf("is empty \n"); return;}
    for(int i = q->head ; i<=q->tail;i++){
        printf("%d\n", q->T[i]);
    }
}
void free_queue(queue* q){
    free(q->T);
    q->T = NULL;
    
}

void add(queue* q , int element){
   if(isFull(q)) {printf("is full \n"); return ;}
   if(isEmpty(q)) q->head++;
   q->T[++q->tail] = element;
}
int pop(queue* q){
    
    if(isEmpty(q)) {printf("is empty \n");   return -1;}
    if(q->T == NULL) {printf("is empty \n"); return -1;}
    int value = q->T[q->head];
    if(q->head == q->tail){
        q->head = q->tail=-1;
    }
    else {
        q->head ++;
    }
    return value;
    
}


int main() {
    queue q ;
    inisialize(&q,5);
    add(&q , 1);
    add(&q , 1);
    add(&q , 1);
    pop(&q);
    pop(&q);
    //printf("%d",isFull(&q));
    afficher(&q);
    free_queue(&q);
    
    return 0;
}