#include<iostream>
#include<stdlib.h>
using namespace std;

//definning the structure for a graph
//V -> represents the number of vertices the graph will contain
//E -> represents the number of edges the graph will contain
//Adj -> represents the adjacency matrix that will contain the connections
struct Graph
{
    int V;
    int E;
    int **Adj;
};

//function to display the adjacency matrix representation
void display(struct Graph *g)
{
    if(!g)
    {
        cout<<"Graph is empty"<<endl;
    }
    //printing the number of vertices and edges of the graph
    cout<<"Number of vertices : "<<g->V<<endl;
    cout<<"Number of edges : "<<g->E<<endl;
    //displaying the adjacency matrix representation
    for(int i=0;i<g->V;i++) 
    {
        for(int j=0;j<g->V;j++)
        {
            cout<<g->Adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

struct Graph *creation()
{
    //creating a pointer to structure of the graph and allocating its memory
    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    //if g contains null, then it means that no memory has been allocated
    if(!g)
    {
        cout<<"Not enough memory for specified size"<<endl;
    }

    //inputting the number of vertices of the graph
    cout<<"Enter the number of vertices in the graph"<<endl;
    cin>>g->V;
    //inputting the number of edges in the graphs
    cout<<"Enter the number of edges in the graph"<<endl;
    cin>>g->E;

    //allocating memory for Adj pointer
    // int **adj
    g->Adj = (int **)malloc(g->V*sizeof(int*));
    for(int i=0;i<g->V;i++)
    {
        g->Adj[i] = (int*)malloc(g->V*sizeof(int));
    }

    //filling the adjacency matrix with 0
    for(int i=0;i<g->V;i++)
    {
        for(int j = 0;j<g->V;j++)
        {
            g->Adj[i][j]=0;
        }
    }

    //now filling the adjacency matrix with 1s if an edge exists between u and v
    int u,v;
    for(int i=0;i<g->E;i++)
    {
        cout<<"Enter u : ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;
        g->Adj[u][v]=1;
        g->Adj[v][u]=1;
    }

    //returning the pointer to structure of graph
    return g;

}

int main()
{
    struct Graph *g = creation();
    display(g);
    return 0;
}