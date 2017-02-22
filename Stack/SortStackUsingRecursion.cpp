#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int arr[100];
int top = -1;

void Push(int data)
{
    if(top == 99)
    {
        cout<<"Stack Full\n";
        return;
    }
    arr[++top] = data;
}

void Pop()
{
    if(top == -1)
    {
        cout<<"Stack Underflow\n";
        return;
    }
    top--;
}

bool IsEmpty()
{
    if(top == -1) return true;
    else return false;
}

int Top()
{
    if(IsEmpty())
    {
        cout<<"Empty Stack\n";
        return -1;
    }
    return arr[top];
}

void Print()
{
    if(IsEmpty())
    {
        cout<<"Empty Stack\n";
        return;
    }
    printf("\n\nSTACK\n----------\n\n");
    int temp = top;
    while(temp > 0)
    {
        printf("| %d |\n",arr[temp]);
        printf(" -----\n");
        temp--;
    }
    printf("| %d |\n",arr[temp]);
    printf(" -----\n");
    printf("\n\n");
}

void sorting(int data)
{
    if(IsEmpty())
        Push(data);
    else{
        int temp = Top(); Pop();
        if(temp < data)
        {
            sorting(temp);
            temp = data;
        }
        else sorting(data);
        Push(temp);
    }
}

void sorted()
{
    if(!IsEmpty())
    {
        int temp = Top(); Pop();
        sorted();
        sorting(temp);
    }
}

int main()
{
    int choice,x;
    printf("\t\t\t\tSTACK PROGRAM\n\n\t\tSorting a Stack Using Recursion\n\n");
    while(1)
    {
        printf("Press 1 for Push operation\nPress 2 for Pop operation\nPress 3 for display\nPress 4 for Top operation\nPress 5 for IsEmpty operation\nPress 6 for Sorting\nPress 7 for exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node\n");
                    scanf("%d",&x);
                    Push(x);
                    break;
            case 2: Pop();
                    break;
            case 3: Print();
                    break;
            case 4: printf("\n\n\t\tTop Element of the stack is %d\n\n\n",Top());
                    break;
            case 5: if(IsEmpty()==true) printf("Stack is Empty\n");
                    else printf("\n\n\t\tStack is NOT Empty\n\n\n");
                    break;
            case 6: sorted();
                    cout<<"Sorted Successfully\n\n\n";
                    break;
            case 7: exit(0);
                    break;
            default : printf("Wrong Choice!\n");
                      break;
        }
    }
    return 0;
}
