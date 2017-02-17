#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    Node* next;
};

Node* head=NULL; //Global variable

void mergeSort(struct Node** headref)
{
    Node* head = *headref;
    if(head == NULL || head->next == NULL)
        return;

}
void Insert(int x)
{
    Node* temp = new Node //Dynamic Memory allocated
    temp->data=x;
    temp->next=head;
    head=temp;
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
    printf("\t\t\t\tMergeSort\n\n");
    while(1)
    {
        printf("Press 1 for insertion\nPress 2 for sort\nPress 3 for display\nPress 4 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node\n");
                    scanf("%d",&x);
                    Insert(x);
                    break;
            case 2: Sort();
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
