#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
}Node;


Node* create(int value){
 Node* node = (Node*)malloc(sizeof(Node));   
 node->data = value;
 node->left = node->right = NULL;
 return node;
}

Node* insert(Node* root ,int value ){
    if(root == NULL) return create(value);
    if(value>root->data) root->right = insert(root->right,value );
    else root->left = insert(root->left,value );
    
    return root;
}


int search(Node* root ,int value ){
    if(root == NULL) return 0;
    if(root->data == value) return 1;
    if(root->data > value) return  search(root->left , value );
    
    return search(root->right, value );
}

void inorder(Node* root){// left root right
    if(root == NULL) return;
    inorder(root->left);
    printf("%d --- ", root->data);
    inorder(root->right);
}


void preorder(Node* root){// root left right
    if(root == NULL) return;
   
    printf("%d --- ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){//  left right root
    if(root == NULL) return;
   
    
    postorder(root->left);
    postorder(root->right);
    printf("%d --- ", root->data);
    
}

int main()
{
    
    Node* root = NULL;
    root = insert(root,50);
    insert(root, 15);
    insert(root, 55);
    insert(root, 70);
    insert(root, 80);
    
    //printf("%d" , search(N,15));
   postorder(root);
    

    return 0;
}
