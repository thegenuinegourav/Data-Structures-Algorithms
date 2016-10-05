//Implementation of Stack using LinkedList
#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top=NULL; //Global variable

void Push(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); //Dynamic Memory allocated
    temp->data=x;
    temp->next=top;
    top=temp;
    printf("\n\t\t\tPUSHED!!\n\n");
    return;
}

void Pop()
{
    if(top==NULL)
    {
        printf("Stack underflow!!\n");
        return;
    }
    struct Node* temp =top;
    top=top->next;
    free(temp);
    printf("\n\t\t\tPopped!!\n\n");
    return;
}

void Print()
{
    printf("\n\nSTACK\n----------\n\n");
    struct Node* temp = top;
    while(temp->next!=NULL)
    {
        printf("| %d |\n",temp->data);
        printf(" -----\n");
        temp=temp->next;
    }
    printf("| %d |\n",temp->data);
    printf(" -----\n");
    printf("\n\n");
}

int Top()
{
    return top->data;
}

bool IsEmpty()
{
    if(top==NULL) return true;
    else return false;
}
int main()
{
    int choice,x;
    bool check;
    printf("\t\t\t\tSTACK PROGRAM\n\n\t\tImplementation of Stack using LinkedList\n\n");
    while(1)
    {
        printf("Press 1 for Push operation\nPress 2 for Pop operation\nPress 3 for display\nPress 4 for Top operation\nPress 5 for IsEmpty operation\nPress 6 for Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node\n");
                    scanf("%d",&x);
                    Push(x);
                    break;
            case 2: Pop();
                    break;
            case 3: Print();
                    break;
            case 4: printf("\n\n\t\tTop Element of the stack is %d\n\n\n",Top());
                    break;
            case 5: if(IsEmpty()==true) printf("Stack is Empty\n");
                    else printf("\n\n\t\tStack is NOT Empty\n\n\n");
                    break;
            case 6: exit(0);
                    break;
            default : printf("Wrong Choice!\n");
                      break;
        }
    }
    return 0;
}
