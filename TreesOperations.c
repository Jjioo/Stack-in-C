#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* create(int data){
   Node* root = (Node*)malloc(sizeof(Node)); 
   root->data = data;
   root->left = root->right = NULL;
   return root;
}
Node* insert(Node* root , int data){
          if(root == NULL) return create(data);
    
          if(data <= root->data) root->left =  insert(root->left ,data);
     else if(data >  root->data) root->right =  insert(root->right,data);
     
     return root;
    
}
void postOrder(Node* root){ //left , right , root
   if(root==NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}
void preOrder(Node* root){ //root ,left , right
   if(root==NULL) return;
    printf("%d ", root->data);
    postOrder(root->left);
    postOrder(root->right);
    
}
void INOrder(Node* root){ //left , root ,right
   if(root==NULL) return;
    
    postOrder(root->left);
    printf("%d ", root->data);
    postOrder(root->right);
    
}
void free_tree(Node* root){
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    printf("%d\n" , root->data);
    free(root);
    
}
int high(Node* root){
    if(root == NULL) return -1;
    int LEFT = high(root->left);
    int RIGHT = high(root->right);
    
     return 1 +  (LEFT>RIGHT?LEFT:RIGHT );
    
}
int max(Node* root){
    if(root == NULL){
        printf("tree is empty \n");
        exit(EXIT_FAILURE);
    }
    Node* c = root;
    int max;
    while(c->right!=NULL){
        c=c->right;
    }
    return c->data;
}
int isBalanced(Node* root){
    if(root==NULL) return 1;
    int LEFT  = high(root->left);
    int RIGHT = high(root->right);
    if(abs(LEFT - RIGHT)>1) return -1;
    return isBalanced(root->left)&&
           isBalanced(root->right);
    
}
int Help1(Node* root , int max , int min){
    if(root == NULL) return 1;
    if(root->data <min || root->data> max) return 0;
    return Help1(root->left , root->data , min) && Help1(root->right , max, root->data );
    
}
int isValide(Node* root){
    return Help1(root , INT_MAX , INT_MIN) == 1;
}


int count(Node* root , int key){
    if(root == NULL) return 0;
    int l =count(root->left , key); 
    int r =count(root->right , key); 
   
   return (root->data == key) + l+r;
    
}

int Max(Node* root){
    if(root==NULL) return INT_MAX;
    Node* c = root;
    while(c->right != NULL){
        c = c->right;
    }
    return c->data;
}

int max(int a,int b){
    return a>b?a:b;
}

int Max_notABR(Node* root){
    if(root==NULL) return INT_MIN;
    int ml = Max_notABR(root->left); 
    int mr = Max_notABR(root->right); 
    return max(root->data , max(ml,mr));
}


int main() {
Node* root = NULL;
root = insert(root , 5); 
insert(root , 15);
insert(root , 5);
//insert(root , 9);
//insert(root , 8);
//insert(root , 7);

//free_tree(root);

printf("%d",Max_notABR(root));

//     5 
//    / \
//   4   15
//  /\   /\
//      9
//     / \
//     8
//    / \
//   7
 

}


