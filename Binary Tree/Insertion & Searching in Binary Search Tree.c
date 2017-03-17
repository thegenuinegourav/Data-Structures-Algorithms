#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* Insert(struct Node* root,int data)
{
    if(root == NULL)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->left=NULL; temp->right = NULL; temp->data = data;
        root=temp;
    }
    else if(root->data <data)
    {
        root->right = Insert(root->right,data);
    }
    else{
        root->left = Insert(root->left,data);
    }
    return root;

};

void breadthTrav(Node* root)
{
    queue<Node*> q;
    Node* current = root;

    while(current != NULL)
    {

    }
}

int main()
{
    struct Node* root = NULL;
    int data,boolean,n,element;

    printf("\t\t\tWelcome to Binary Tree!\n\n\t\tBreadth First Traversal\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);
        n--;
    }
    printf("INSERTION Completed!\n\n");
    printf("Breadth First Traversal\n");
    breadthTrav(root);

    return 0;
}
