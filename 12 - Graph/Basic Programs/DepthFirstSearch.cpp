#include<iostream>
using namespace std;
#include<stack>
#include<vector>
//defining the structure of graph
struct graph 
{
    int vertices;
    int edges;
    int **adj;
    //assigining the vertices and edges in the constructor of structure
    graph(int v,int e)
    {
        vertices = v;
        edges = e;
    }
};

struct graph *create()
{
    int u,v,e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;

    struct graph *g = new graph(v,e);
    //if g contains null, it means that memory has not been assigned
    if(!g)
    {
        cout<<"Memory not available!!!!"<<endl;
        return NULL;
    } 
    //assigining the memory for the adjacency matrix
    g->adj = (int**)malloc(g->vertices*sizeof(int*));
    for(int i=0;i<g->vertices;i++)
    {
        g->adj[i] = (int*)malloc(g->vertices*sizeof(int));
    }

    //filling the adjcency matrix with 0
    for(int i=0;i<g->vertices;i++)
    {
        fill(g->adj[i],g->adj[i]+g->vertices,0);
    }   

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

void DFS(struct graph *g,int n)
{
    stack<int> st;
    vector<bool> visited(g->vertices);
    //initially all the nodes will not be visited
    fill(visited.begin(),visited.end(),false);

    st.push(n);
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        cout<<temp<<endl;
        visited[temp]=true;

        for(int i=0;i<g->vertices;i++)
        {
            if(g->adj[temp][i]==1 && visited[i]==false)
            {
                st.push(i);
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
    //calling the create functino to create a graph 
    struct graph *g = create();
    int n;
    //getting the node from where we have to start the traversing the graph
    cout<<"Enter the node with which you want to traverse the graph : ";
    cin>>n;
    //calling the depth first search function 
    DFS(g,n);
}