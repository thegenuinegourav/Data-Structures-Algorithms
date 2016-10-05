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

int IsBST(struct Node* root, int min, int max)
{
    if(root==NULL) return 1;
    else if(root->data<max && root->data > min && IsBST(root->left,min,root->data) && IsBST(root->right,root->data,max)) return 1;
    else return 0;
}


int main()
{
    struct Node* root = NULL;
    int n,element,boolean;

    printf("\t\t\tWelcome to Binary Search Tree!\n\n\t\tHeight of a BST\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);
        n--;
    }
    printf("INSERTION Completed!\n\n"); //Inserting elements in a BST way only, so everytime it will be a BST
    boolean = IsBST(root,-32767,32768);
    if(boolean == 1) printf("Given Binary Tree is a Binary Search Tree\n");
    else printf("Given Binary Tree is not a Binary Search Tree\n\n");
    return 0;
}
