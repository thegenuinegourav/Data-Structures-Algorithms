#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

char arr[100];
int top = -1;

void Push(char data)
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

int getPriority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return -1;
    }
}

int IsOperand(char ch)
{
    return ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'));
}

int IsOperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return 1;
        default: return 0;
    }
}

int IsOpeningBrace(char ch)
{
    return (ch == '(');
}

int IsClosingBrace(char ch)
{
    return (ch == ')');
}

void InfixToPostfix(char* exp)
{
    int i=0,k=-1;
    char result[strlen(exp)];
    while(exp[i]!='\0')
    {
        if(IsOperand(exp[i]))
            result[++k] = exp[i];
        else if(IsOperator(exp[i]))
        {
            while(!IsEmpty() && !IsOpeningBrace(Top()) && (getPriority(exp[i]) <= getPriority(Top())))
            {
                result[++k] = Top(); Pop();
            }
            Push(exp[i]);
        }
        else if(IsOpeningBrace(exp[i]))
            Push(exp[i]);
        else if(IsClosingBrace(exp[i]))
        {
            while(!IsEmpty() && !IsOpeningBrace(Top()))
            {
                result[++k] = Top(); Pop();
            }
            Pop();
        }
        i++;
    }
    while(!IsEmpty())
    {
        result[++k] = Top(); Pop();
    }
    result[++k]='\0';
    cout<<"Converted PostFix Expression: "<<result;
}

int main()
{
    char exp[100];
    cout<<"Enter the Infix expression\n";
    cin>>exp;
    InfixToPostfix(exp);
    return 0;
}
