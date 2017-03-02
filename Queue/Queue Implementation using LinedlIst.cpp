#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;


int IsEmpty()
{
    if(front==NULL) return 1;
    else return 0;
}

Node* GetNewNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = front;
    return temp;
}

void Enqueue(int data)
{
    Node* temp = GetNewNode(data);
    if(front == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    if(IsEmpty()) return;
    Node* temp = front;
    if(front==rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    delete temp;
}

int Front()
{
    if(!IsEmpty())
        return front->data;
    else return -1;
}

void Print()
{
    if(!IsEmpty())
    {
        Node* temp = front;
        printf("\n\n");
        while(temp != rear)
        {
            printf("%d  |  ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
        printf("\n\n");
    }
    else{
        printf("\nQueue is Empty!\n");
        return;
    }

}

int main()
{
    int choice,element;
    printf("\t\t\tQUEUE\n\n");
    while(1)
    {
        printf("Press 1 to enter element in a queue\nPress 2 to delete from queue\nPress 3 for check whether queue is empty or not\nPress 4 to print front element of a queue\nPress 5 to display the queue\nPress 6 to exit\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&element);
                    Enqueue(element);
                    break;
            case 2: Dequeue(); break;
            case 3: if(IsEmpty()==1) printf("Queue is empty\n");
                    else printf("Queue is not empty\n"); break;
            case 4: printf("Front Element of the queue: %d\n",Front()); break;
            case 5: Print(); break;
            case 6: exit(0); break;
            default : printf("Enter correct choice\n"); break;
        }
    }
    return 0;
}
