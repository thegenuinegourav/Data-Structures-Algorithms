#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* link;
};

Node *head = NULL,*rear = NULL;

void insert(int data)
{
    Node* temp = new Node;
    temp->data = data;
    if(head == NULL)
    {
        head = temp;
    }
    else{
        rear->link = temp;
    }
    temp->link = NULL;
    rear = temp;
}

void print()
{
    queue<Node*> even, odd;
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data %2 == 0)
            even.push(temp);
        else
            odd.push(temp);

        temp = temp->link;
    }

    while(!even.empty())
    {
        temp = even.front();
        cout<<temp->data<<" ";
        even.pop();
        temp = temp->link;
    }
    while(!odd.empty())
    {
        temp = odd.front();
        cout<<temp->data<<" ";
        odd.pop();
        temp = temp->link;
    }
    while(!even.empty()) even.pop();
    while(!odd.empty()) odd.pop();
}

int main() {
	int t,n,data;
	cin>>t;
	while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin>>data;
            insert(data);
        }
        print();
        head=NULL;
        rear=NULL;
    }
	return 0;
}
