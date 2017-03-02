#include <stdio.h>
#include <stdlib.h>

#define N 5
int front=-1,rear=-1;
int A[N];

int IsEmpty()
{
    if(front==-1) return 1;
    else return 0;
}

void Enqueue(int data)
{
    if((rear+1)%N == front) return;
    else if(IsEmpty())
    {
        front=rear=0;
    }
    else rear = (rear+1)%N;
    A[rear] = data;
}

void Dequeue()
{
    if(IsEmpty()) return;
    else if(front==rear)
    {
        front=-1; rear=-1;
    }
    else front=(front+1)%N;
}

int Front()
{
    if(!IsEmpty())
        return A[front];
    else return -1;
}

void Print()
{
    if(!IsEmpty)
    {
    int i;
    printf("\n\n");
    i = front;
    while(i != rear)
    {
        printf("%d  |  ",A[i]);
        i=(i+1)%N;
    }
    printf("%d",A[rear]);
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
