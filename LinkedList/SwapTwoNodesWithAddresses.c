//Inserting and Deleting node at beginning in a nextedList
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

void Swap(int a,int b)
{
    struct Node* temp=head;
    struct Node *p1,*p2,*c1,*c2;
    struct Node* temp2;

    if(head->data!=a)
    {
        while(temp->next->data!=a)
        {
        temp=temp->next;
        }
        p1=temp;
        c1=temp->next;
    }

    temp=head;

    if(head->data!=b)
    {
         while(temp->next->data!=b && head->data!=b)
         {
          temp=temp->next;
         }
         p2=temp;
         c2=temp->next;
    }

    if(head->data!=a && head->data!=b)
    {
        p2->next=c1;
        p1->next=c2;
        temp2=c1->next;
        c1->next=c2->next;
        c2->next=temp2;
    }
    else if(head->data == a)
    {
        c1=head;
        p2->next=c1;
        head=c2;
        temp2=c1->next;
        c1->next=c2->next;
        c2->next=temp2;
    }
    else if(head->data == b)
    {
        c2=head;
        p1->next=c2;
        head=c1;
        temp2=c2->next;
        c2->next=c1->next;
        c1->next=temp2;
    }
}


int main()
{
    int data1,data2;
    printf("\t\t\t\tLINKEDLIST PROGRAM\n\n\t\tSwap nodes in a linked list without swapping data\n\n");
    Insert(10); Insert(15); Insert(12); Insert(13); Insert(20); Insert(14);
    Print();
    printf("Enter the two data values to be swapped\n");
    scanf("%d %d",&data1,&data2);
    Swap(data1,data2);
    Print();
    return 0;
}
