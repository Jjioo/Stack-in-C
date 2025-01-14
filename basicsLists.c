#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;


Node* create(int data){
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->next = NULL;
    return root;
    
}
Node* insert(Node* root,int data){
    if(root == NULL) return create(data);
    root->next =  insert(root->next , data);
    return root;
     
}

Node* insertAtStart(Node* root,int data){
    Node* newNode = create(data);
    newNode->next = root;
    return newNode;
}


void display(Node* root){
    if(root==NULL) return;
     printf("%d ", root->data);
 display(root->next);
      
  
    
}
void count(Node* root){
    int c = 0;
    while(root!=NULL){
        c++;
        root =root->next;
    }
    printf("%d ",c);
}

Node* insertPos(Node* root , int data , int position){
    if(position<0){
        printf("Invalid position!\n");
        return root;
    }
    Node* newNode = create(data);
    if(position == 0)  return insertAtStart(root , data);
    Node* current = root;
    int index = 0;
    while(current!=NULL && index < position-1){
        current = current->next;
        index ++;
    }
     // If the position is out of bounds
    if (current == NULL) {
        printf("Position is out of bounds!\n");
        free(newNode); // Free the unused node
        return root;
    }
    newNode->next  = current->next;
    current->next = newNode;
    
    return root;
    
  
}



int main()
{
   Node* root = NULL;
   root = insert(root,10);
   root = insert(root,20);
   root =insert(root,30);
   root = insertAtStart(root,22);
   //display(root);
   root = insertPos(root , 44 ,4 );
   display(root);
    return 0;
}