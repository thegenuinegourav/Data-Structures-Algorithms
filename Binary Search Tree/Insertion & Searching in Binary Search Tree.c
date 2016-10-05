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

int Search(struct Node* root, int data)
{
    if(root == NULL) return 0;
    else if(root->data == data) return 1;
    else if(root->data < data) Search(root->right,data);
    else Search(root->left,data);
}

int main()
{
    struct Node* root = NULL;
    int data,boolean,n,element;

    printf("\t\t\tWelcome to Binary Search Tree!\n\n\t\tINSERTION & SEARCHING\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);

        n--;
    }
    printf("INSERTION Completed!\n\n");
    printf("Enter the number that you want to search in a binary tree\n");
    scanf("%d",&data);
    boolean = Search(root,data);
    if(boolean == 1) printf("FOUND\n");
    else printf("NOT FOUND\n");

    return 0;
}
