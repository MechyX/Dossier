#include<stdio.h>
#include<stdlib.h>
typedef struct Node Node;
typedef struct Fibtree Fibtree;

struct Node{
    Node* right;
    Node* left;
    int data;
};

struct Fibtree{
    Node *root;
    int order;
};

Node* newNode(int data,Node *left, Node*right){
    Node* root = (Node*) malloc(sizeof(Node));
    root->left = left;
    root->right = right;
    root->data = data;
    return root;
}

Node* constructFibonacciTree(int n){
    if(n<2){
        Node *root = newNode(n,NULL, NULL);
        return root;
    }
        
    else{
        Node* left = constructFibonacciTree( n - 1 );
        Node* right = constructFibonacciTree( n - 2 );
        return newNode(left->data+right->data,left,right);
    }
}

void printFibSeries(Node* node) 
{ 
     if (node == NULL) 
        return; 
    
    printFibSeries(node->left);
    printf("%d ",node->data);
}  

void main(){
    Fibtree t;
    t.order = 5;
    t.root = constructFibonacciTree(t.order);
    printFibSeries(t.root);
}