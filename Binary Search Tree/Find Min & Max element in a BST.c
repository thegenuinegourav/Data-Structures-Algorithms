#include <stdio.h>
#include <stdlib.h>

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

int FindMin(struct Node* root)
{
    if(root==NULL) return -1; //null tree
    else if(root->left==NULL) return root->data;
    else return FindMin(root->left);
}

int FindMax(struct Node* root)
{
    if(root==NULL) return -1;
    else if(root->right==NULL) return root->data;
    else return FindMax(root->right);
}

int main()
{
    struct Node* root = NULL;
    int n,element;

    printf("\t\t\tWelcome to Binary Search Tree!\n\n\t\tMin-Max Element & INSERTION\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);
        n--;
    }
    printf("INSERTION Completed!\n\n");
    printf("Minimum Element : %d\nMaximum Element : %d",FindMin(root),FindMax(root));
    return 0;
}
