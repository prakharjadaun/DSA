#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//definning the structure of graph
struct graph 
{
    int edges;
    int vertices;
    int **adj;
    graph(int v,int e)
    {
        edges = e;
        vertices = v;
    }
};

//function to create graph using adjacency matrix
struct graph *create()
{
    int u,v,e;
    //getting the number of vertices and edges of graph
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    //instantiating an object of graph structure
    struct graph *g = new graph(v,e);

    //allocating the memory for the adjacency matrix 
    g->adj = (int**)malloc(v*sizeof(int*));
    for(int i=0;i<v;i++)
    {
        g->adj[i] = (int *)malloc(v*sizeof(int));
    }
    //filling the matrix with 0
    for(int i=0;i<v;i++)
    {
        fill(g->adj[i],g->adj[i]+v,0);
    }

    //getting the name of the vertices between which the edges exists
    for(int i=0;i<e;i++)
    {
        cout<<endl;
        cout<<"Enter u : ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;

        g->adj[u][v] = 1;
        g->adj[v][u] = 1;
    }
    return g;
}

void BFS(struct graph *g,int n)
{
    queue<int> q;
    vector<bool> visited(g->vertices);
    fill(visited.begin(),visited.end(),false);
    q.push(n);
    while(!q.empty())  
    {
        int temp = q.front();
        q.pop();
        cout<<temp<<endl;
        visited[temp]=true;
        for(int i=0;i<g->vertices;i++)
        {
            if(g->adj[temp][i]==1 && visited[i]==false)
            {
                q.push(i);
            }
        }
    }

    //printing the visited vector
    for(int i=0;i<visited.size();i++)
    {
        cout<<visited[i]<<" ";

    }
    cout<<endl;

}


int main()
{
    int n;
    struct graph *g = create();
    cout<<"Enter the node with which you want to traverse : ";
    cin>>n;
    BFS(g,n);
}   