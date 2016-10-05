//Inserting and Deleting node at beginning in a LinkedList
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node *head1=NULL,*head2=NULL; //Global variable

void Insert1(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); //Dynamic Memory allocated
    temp->data=x;
    temp->link=head1;
    head1=temp;
     printf("\n\t\t\tINSERTED!!\n\n");
    return;
}

void Insert2(int x)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node)); //Dynamic Memory allocated
    temp->data=x;
    temp->link=head2;
    head2=temp;
     printf("\n\t\t\tINSERTED!!\n\n");
    return;
}

void Print1()
{
    printf("\n\n 1st LINKEDLIST : ");
    struct Node* temp = head1;
    while(temp->link!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
    printf("\n\n");
}

void Print2()
{
    printf("\n\n 2nd LINKEDLIST : ");
    struct Node* temp = head2;
    while(temp->link!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
    printf("\n\n");
}

struct Node* Insert(int data,struct Node* head)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;
    if(head == NULL) return temp;
    else{
        struct Node* temp1 = head;
        while(temp1->link != NULL)
        {
            temp1=temp1->link;
        }
        temp1->link = temp;
        return head;
    }
}

struct Node* SortedMerge(struct Node* temp1, struct Node* temp2)
{
    struct Node* head=NULL;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp2==NULL)
        {
            while(temp1!=NULL)
            {
                head=Insert(temp1->data,head);
                temp1=temp1->link;
            }
            return head;
        }
        if(temp1==NULL)
        {
            while(temp2!=NULL)
            {
                head=Insert(temp2->data,head);
                temp2=temp2->link;
            }
            return head;
        }
        if(temp1->data<temp2->data)
        {
            head = Insert(temp1->data,head);
            temp1=temp1->link;
        }else
        {
            head = Insert(temp2->data,head);
            temp2=temp2->link;
        }
    }
    return head;
}


int main()
{
    int choice,x;
    struct Node* head=NULL;
    printf("\t\t\t\tLINKEDLIST PROGRAM\n\n\t\tMerge two sorted linked lists\n\n");
    Insert1(15);  //Insert1(10); Insert1(5);
    Insert2(20); Insert2(3);  Insert2(2);
    Print1(); Print2();

    head=SortedMerge(head1,head2);
    printf("Sorted LinkedList :  ");
    if(head==NULL) printf("Empty");
    while(head!=NULL)
    {
        printf("%d ",head->data); head=head->link;
    }




    return 0;
}
