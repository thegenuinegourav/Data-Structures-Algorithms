#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};


Node* GetNewNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    return temp;
}

void InsertAtBegin(Node** headref,int data)
{
    Node* temp = GetNewNode(data);
    temp->prev = NULL;
    if(*headref == NULL)
        temp->next = NULL;
    else
    {
        temp->next = *headref;
        (*headref)->prev = temp;
    }
    *headref = temp;

}

void print(Node** headref)
{
    Node* temp = *headref;
    cout<<"\nForward Printing using next Pointer:\n";
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<"\n\nBackward Printing using prev Pointer:\n";
    while(temp->prev != NULL)
    {
        cout<<temp->data<<" <-> ";
        temp = temp->prev;
    }
    cout<<temp->data;
    cout<<"\n\n";
}

Node* getRear(Node** head)
{
    Node* temp = *head;
    while(temp->next!=NULL)
        temp = temp->next;
    return temp;
}

Node* partition(Node* start, Node* last)
{
    int pivot = last->data;
    Node* pIndex = start;
    Node* temp = start;
    int t;
    while(temp != last)
    {
        if(temp->data < pIndex->data)
        {
          t= temp->data;
          temp->data = pIndex->data;
          pIndex->data = t;
          pIndex = pIndex->next;
        }
        temp = temp->next;
    }
    t = pIndex->data;
    pIndex->data = last->data;
    last->data = t;
    return pIndex;
}

void quickSort(Node* start, Node* last)
{
    if(start == last) return;
    Node* pivot = partition(start,last);
    quickSort(start,pivot->prev);
    quickSort(pivot->next,last);
}

void _quickSort(Node *head)
{
    // Find last node
    Node *h = getRear(&head);

    // Call the recursive QuickSort
    quickSort(head, h);
}

int main() {
	int choice,element,pos;
	Node* head = NULL;
    cout<<"\t\t\tQuick Sort in DOUBLY LINKEDLIST\n\n";
    while(1)
    {
        cout<<"Press 1 to enter element At the front of the DLL\nPress 2 to perform QuickSort\nPress 3 to exit\nEnter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the element\n";
                    cin>>element;
                    InsertAtBegin(&head,element);
                    print(&head);
                    break;
            case 2: _quickSort(head);
                    print(&head);
                    break;
            case 3: exit(0); break;
            default : cout<<"Enter correct choice\n"; break;
        }
    }
    return 0;
}
