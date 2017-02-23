
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

void NGE()
{
    int next,i;
    Push(a[0]);
    for(i=1;i<n;i++)
    {
        next = a[i];
        while(!IsEmpty() && next > Top())
        {
            cout<<Top()<<"\t -->\t"<<next<<"\n";
            Pop();
        }
        Push(next);
    }
    while(!IsEmpty())
    {
        cout<<Top()<<"\t -->\t-1\n";
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
    cout<<"Next Gretor Element: \nElement\t\tNGE\n";
    NGE();
    return 0;
}
