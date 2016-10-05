#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

int FindMax(int a,int b)
{
    if(a>b) return a;
    else return b;
}

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

int FindHeight(struct Node* root)
{
    if(root==NULL) return -1;
    else return 1+ FindMax(FindHeight(root->left),FindHeight(root->right));
}


int main()
{
    struct Node* root = NULL;
    int n,element;

    printf("\t\t\tWelcome to Binary Search Tree!\n\n\t\tHeight of a BST\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);
        n--;
    }
    printf("INSERTION Completed!\n\n");
    printf("Height of a Binary Search Tree : %d",FindHeight(root));
    return 0;
}
