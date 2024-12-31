#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* T;
    int head,tail,size,count;
}queue;

void initialize(queue* q,int s){
    q->T = (int*) malloc(s * sizeof(int));
    q->head  =  0;
    q->tail  = -1;
    q->size  =  s;
    q->count =  0;
    
    
}
void free_queue(queue* q){
    free(q->T);
    q->T = NULL;
    
}
int isEmpty(queue* q){
    return q->count == 0;
}
int isFull(queue* q){
    return q->count == q->size;
}
void affichage(queue* q){
    if(isEmpty(q)) return ;
    for(int i =0;i<q->count;i++){
        int index = (q->head +i) % q->size;
        printf("%d",q->T[index]);
        
    }
    
}

void add(queue* q , int element){
    if(isFull(q)) return ;
    q->tail = (q->tail+1) % q->size;
    q->T[q->tail] = element;
    q->count ++;
}
int pop(queue* q){
    if(q->T == NULL) return -1;
    if(isEmpty(q))   return -1;
    int value = q->T[q->head];
    
    q->head = (q->head+1) % q->size;
    q->count --;
    return value;
    
    
}




int main() {
   queue q;
   initialize(&q,5);
   for(int i=1;i<=5;i++)
   add(&q , i);
   
   affichage(&q);
   //free_queue(&q);
   free(q.T);
  
   
   
    return 0;
}