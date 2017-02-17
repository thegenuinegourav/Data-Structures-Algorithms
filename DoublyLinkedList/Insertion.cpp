#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* rear = NULL; //For insertAtEnd

Node* GetNewNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    return temp;
}

void InsertAtBegin(int data)
{
    Node* temp = GetNewNode(data);
    temp->prev = NULL;
    if(head == NULL)
        temp->next = NULL;
    else
        temp->next = head;
    head = temp;
}

void InsertAtEnd(int data)
{
    Node* temp = GetNewNode(data);
    temp->next = NULL;
    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
    }
    rear = temp;
}

int getTotalNodes()
{
    int count=0;
    Node* temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void InsertAtPosition(int data, int pos)
{
    if(pos==0)
    {
        cout<<"Incorrect position"; return;
    }

    if(pos > getTotalNodes())
    {
        InsertAtEnd(data); return;
    }

    if(head==NULL || pos == 1){
        InsertAtBegin(data); return;
    }

    Node* temp1 = head;
    pos--;
    while(--pos && temp1!=NULL)
    {
        temp1 = temp1->next;
    }
    Node* temp = GetNewNode(data);
    temp->next = temp1->next;
    (temp1->next)->prev = temp;
    temp->prev = temp1;
    temp1->next = temp;
    return;
}

void print()
{
    Node* temp = head;
    cout<<"\n";
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<"\n\n";
}

int main() {
	int choice,element,pos;
    cout<<"\t\t\tDOUBLY LINKEDLIST\n\n";
    while(1)
    {
        cout<<"Press 1 to enter element At the front of the DLL\nPress 2 to enter element After a given node\nPress 3 to enter element At the end of the DLL\nPress 4 to exit\nEnter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the element\n";
                    cin>>element;
                    InsertAtBegin(element);
                    print();
                    break;
            case 2: cout<<"Enter the element\n";
                    cin>>element;
                    cout<<"Enter the position\n";
                    cin>>pos;
                    InsertAtPosition(element,pos);
                    print();
                    break;
            case 3: cout<<"Enter the element\n";
                    cin>>element;
                    InsertAtEnd(element);
                    print();
                    break;
            case 4: exit(0); break;
            default : cout<<"Enter correct choice\n"; break;
        }
    }
    return 0;
}
