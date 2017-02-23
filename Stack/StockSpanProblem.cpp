

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int arr[100]; //For Implementing Stack
int top = -1;
int a[100]; //Input Array
int n; //Size of inputted array;

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

void SSP()
{
    int i;
    Push(n-1);
    for(i=n-2; i>=0; i--)
    {
        while(!IsEmpty() && a[i] > a[Top()])
        {
            a[Top()] = Top() - i;
            Pop();
        }
        Push(i);
    }
    while(!IsEmpty())
    {
        a[Top()] = 1;
        Pop();
    }
}

int main()
{
    int i;
    cout<<"Enter the size of an array\n";
    cin>>n;
    cout<<"Enter the elements of an array\n";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"The Stock Span Array of a given array:\n";
    SSP();
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
