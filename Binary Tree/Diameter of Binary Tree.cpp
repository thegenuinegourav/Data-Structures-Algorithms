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
    else if(root->data <= data)
    {
        root->right = Insert(root->right,data);
    }
    else{
        root->left = Insert(root->left,data);
    }
    return root;

};

int height(Node* root)
{
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(Node* root)
{
    if(root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(lheight + rheight + 1 , max(ldiameter,rdiameter));
}

int main()
{
    struct Node* root = NULL;
    int data,boolean,n,element;

    printf("\t\t\tWelcome to Binary Tree!\n\n\t\tDiameter of a Binary Tree\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);
        n--;
    }
    printf("INSERTION Completed!\n\n");
    printf("Diameter of a Binary Tree is %d\n",diameter(root) + 1);

    return 0;
}
