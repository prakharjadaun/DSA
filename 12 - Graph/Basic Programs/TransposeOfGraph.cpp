#include<iostream>
#include<vector>
using namespace std;

//function to connect the edge
void connectEdge(vector<int> adjlist[],int u,int v)
{
    adjlist[u].push_back(v);
}

//function to display the adjacency list
void display(vector<int> adjlist[], int v)
{
    cout<<"Number of vertices in graph : "<<v<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<" --> ";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
}

//function to generate transpose of graph
void generateTranspose(vector<int> transpose[],vector<int> adjlist[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<adjlist[i].size();j++)
        {
            transpose[adjlist[i][j]].push_back(i);
        }
    }
}

int main()
{
    int m,n,V,E;
    cout<<"Enter the vertices : ";
    cin>>V;

    vector<int> adjlist[V];
    cout<<"Enter the number of edges : ";
    cin>>E;

    for(int i=0;i<E;i++)
    {
        cout<<"Enter u : ";
        cin>>m;
        cout<<"Enter v : ";
        cin>>n;
        connectEdge(adjlist,m,n);
    }
    //function called for displaying the adjacency list
    display(adjlist,V);

    vector<int> transpose[V];

    //function to generate transpose 
    generateTranspose(transpose,adjlist,V);
    //displaying the tranposed adjacency list
    display(transpose,V);

}