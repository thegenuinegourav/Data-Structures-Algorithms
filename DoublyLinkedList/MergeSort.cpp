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
        temp->next = *headref;
    *headref = temp;

}

void print(Node** headref)
{
    Node* temp = *headref;
    cout<<"\n";
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<"\n\n";
}

void split(Node* head, Node** left, Node** right)
{
    if(head == NULL || head->next == NULL)
    {
        *left = head;
        *right = NULL;
        return;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

Node* merge(Node* left, Node* right)
{
    if(left == NULL && right == NULL) return NULL;
    if(left == NULL) return right;
    if(right == NULL) return left;
    if(left->data < right->data)
    {
        left->next = merge(left->next,right);
        return left;
    }
    else{
        right->next = merge(left, right->next);
        return right;
    }
}

void mergeSort(Node** headref)
{
    Node* head = *headref;
    if(head == NULL || head->next == NULL)
        return;
    Node *left, *right;
    split(head,&left,&right);
    mergeSort(&left);
    mergeSort(&right);
    *headref = merge(left,right);
}

int main() {
	int choice,element,pos;
	Node* head = NULL;
    cout<<"\t\t\tMerge Sort in DOUBLY LINKEDLIST\n\n";
    while(1)
    {
        cout<<"Press 1 to enter element At the front of the DLL\nPress 2 to perform MergeSort\nPress 3 to exit\nEnter your choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter the element\n";
                    cin>>element;
                    InsertAtBegin(&head,element);
                    print(&head);
                    break;
            case 2: mergeSort(&head);
                    print(&head);
                    break;
            case 3: exit(0); break;
            default : cout<<"Enter correct choice\n"; break;
        }
    }
    return 0;
}
