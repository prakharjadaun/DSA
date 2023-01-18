#include<vector>
#include<iostream>
using namespace std;
//using vector container for implementing the adjacency list representation

//function to connect edges to the adjacency list 
void connectEdges(vector<int> adjlist[])
{
    int E,u,v;
    cout<<"Enter the number of edges that you want : ";
    cin>>E;
    //iterating the number of edge times 
    for(int i=0;i<E;i++)
    {
        cout<<"Enter u : ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;
        adjlist[u].push_back(v);
    }
}

//function  to display the adjacency list
void display(vector<int> adjlist[],int v)
{
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


int main()
{
    //getting the number of vertices from the user
    int v;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    
    vector<int> adjlist[v];
    connectEdges(adjlist);
    //function to represent the adjacency list 
    display(adjlist,v);
}