#include <iostream>

using namespace std;

int arr[100];
int top1=-1, top2=99;

void Push1(int data)
{
    if(top1 < top2-1)
        arr[++top1] = data;
    else
        cout<<"Stack1 Overflow";
}

void Pop1()
{
    if(top1 == -1) cout<<"Stack1 Underflow";
    else top1--;
}

bool IsEmpty1()
{
    if(top1 == -1) return true;
    else return false;
}

int Top1()
{
    if(!IsEmpty1())
        return arr[top1];
    else
        return -1;
}


void Push2(int data)
{
    if(top1 < top2-1)
        arr[--top2] = data;
    else
        cout<<"Stack2 Overflow";
}

void Pop2()
{
    if(top2 == 99) cout<<"Stack2 Underflow";
    else top2++;
}

bool IsEmpty2()
{
    if(top2 == 99) return true;
    else return false;
}

int Top2()
{
    if(!IsEmpty2())
        return arr[top2];
    else
        return -1;
}


int main()
{
    Push1(5);
    Push2(10);
    Push2(15);
    Push1(11);
    Push2(7);
    cout << "Popped element from stack1 is " << Top1();
    Pop1();
    Push2(40);
    cout << "\nPopped element from stack2 is " << Top2();
    Pop2();
    return 0;
}
