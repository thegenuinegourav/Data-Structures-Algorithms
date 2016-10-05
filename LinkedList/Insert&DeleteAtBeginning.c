//Inserting and Deleting node at beginning in a LinkedList
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=NULL; //Global variable

void Insert(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); //Dynamic Memory allocated
    temp->data=x;
    temp->next=head;
    head=temp;
     printf("\n\t\t\tINSERTED!!\n\n");
    return;
}

void Delete()
{
    if(head==NULL)
    {
        printf("No element to delete\n");
        return;
    }
    struct Node* temp =head;
    head=head->next;
    free(temp);
    printf("\n\t\t\tDELETED!!\n\n");
    return;
}

void Print()
{
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
    int choice,x;
    printf("\t\t\t\tLINKEDLIST PROGRAM\n\n\t\tInsertion and Deletion of nodes at beginning\n\n");
    while(1)
    {
        printf("Press 1 for insertion\nPress 2 for deletion\nPress 3 for display\nPress 4 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node\n");
                    scanf("%d",&x);
                    Insert(x);
                    break;
            case 2: Delete();
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
