#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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

void inorderTrav(Node* root)
{
    stack<Node*> s;
    if(root == NULL) return;
    Node* current = root;
    while(true)
    {
        if(current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        else{
            if(!s.empty())
            {
                current = s.top(); s.pop();
                cout<<current->data<<"  ";
                current = current->right;
            }
            else
                break;
        }
    }
}

int main()
{
    struct Node* root = NULL;
    int data,boolean,n,element;

    printf("\t\t\tWelcome to Binary Tree!\n\n\t\tInorder Traversal without Recursion\n\nEnter the number of elements that you want to insert\n");
    scanf("%d",&n);
    while(n)
    {
        printf("Enter the element\n");
        scanf("%d",&element);
        root = Insert(root,element);
        n--;
    }
    printf("INSERTION Completed!\n\n");
    printf("Inorder Traversal\n");
    inorderTrav(root);

    return 0;
}
