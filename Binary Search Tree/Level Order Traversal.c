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

void Preorder(struct Node* root)
{
    if(root==NULL) return;
    printf("%d  |  ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct Node* root)
{
    if(root==NULL) return;
    Inorder(root->left);
    printf("%d  |  ",root->data);
    Inorder(root->right);
}

void Postorder(struct Node* root)
{
    if(root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d  |  ",root->data);
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
    printf("PreOrder Traversal of a Binary Search Tree\n\n");
    Preorder(root);
    printf("\n\nInorder Traversal of a Binary Search Tree\n\n");
    Inorder(root);
    printf("\n\nPostOrder Traversal of a Binary Search Tree\n\n");
    Postorder(root);
    return 0;
}
