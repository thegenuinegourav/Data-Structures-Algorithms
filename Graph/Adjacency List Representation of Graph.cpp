#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int dest;
    Node* next;
};

struct AdjList
{
    Node* head;
};

struct Graph
{
    int v;
    AdjList* arr;
};

Graph* createGraph(int v)
{
    Graph* graph = new Graph;
    graph->v = v;
    graph->arr = (struct AdjList*) malloc(v * sizeof(struct AdjList));
    for(int i=0;i<v;i++)
    {
        graph->arr[i].head = NULL;
    }

    return graph;
}

Node* getNewNode(int dest)
{
    Node* node = new Node;
    node->dest = dest;
    node->next = NULL;
    return node;
}
void addEdge(Graph* graph, int src, int dest)
{
    Node* node = getNewNode(dest);
    node->next = graph->arr[src].head;
    graph->arr[src].head = node;

    node = getNewNode(src);
    node->next = graph->arr[dest].head;
    graph->arr[dest].head = node;
}

void printGraph(Graph* graph)
{
    for(int i=0;i<graph->v;i++)
    {
        cout<<"Adjacency List of "<<i<<" Node are ";
        Node* temp = graph->arr[i].head;
        while(temp->next!=NULL)
        {
            cout<<temp->dest<<" -> ";
            temp = temp->next;
        }
        cout<<temp->dest<<"\n";
    }
}

int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}
