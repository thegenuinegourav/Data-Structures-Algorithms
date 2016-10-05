#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=NULL; //Global variable

void Insert(int x,int n)
{
    int i;
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); //Dynamic Memory allocated
    temp->data=x;
    if(n==1 || head==NULL)
    {
        temp->next=head;
        head=temp;
        return;
    }
    struct Node* temp1=head;
    for(i=1;i<n-1;i++)
    {
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
    printf("\n\t\t\tINSERTED!!\n\n");
    return;
}

void Delete(int n)
{
    int i;
    if(head==NULL)
    {
        printf("No element to delete\n");
        return;
    }
    struct Node* temp =head;
    if(n==1)
    {
        head=head->next;
        free(temp);
        printf("\n\t\t\tDELETED!!\n\n");
        return;
    }
    for(i=1;i<n-1;i++)
    {
        temp=temp->next;
    }
    struct Node* temp1 = temp->next;
    temp->next=temp1->next;
    free(temp1);
    printf("\n\t\t\tDELETED!!\n\n");
    return;
}

void Print()
{
    if(head==NULL)
    {
        printf("\n\nEmpty LinkedList!!\n");
        return;
    }
    printf("\n\nLINKEDLIST : ");
    struct Node* temp = head;
    while(temp->next!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n\n");
}


int main()
{
    int choice,x,n;
    printf("\t\t\t\tLINKEDLIST PROGRAM\n\n\t\tInsertion and Deletion of nodes at nth position\n\n");
    while(1)
    {
        printf("Press 1 for insertion\nPress 2 for deletion\nPress 3 for display\nPress 4 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node\n");
                    scanf("%d",&x);
                    printf("Enter the position of the node\n");
                    scanf("%d",&n);
                    Insert(x,n);
                    break;
            case 2: printf("Enter the position of the node\n");
                    scanf("%d",&n);
                    Delete(n);
                    break;
            case 3: Print();
                    break;
            case 4: exit(0);
            default : printf("Wrong Choice!\n");
                      break;
        }
    }
    return 0;
}
