#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//function to create the adjlist 
void connectEdge(vector<int> adjlist[])
{
    int e,u,v;
    cout<<"Enter the edges : ";
    cin>> e;

    for(int i=0;i<e;i++)
    {
        cout<<"Enter u: ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;

        adjlist[u].push_back(v); 
    }
}
//BFS function using adjacency list
void BFS(vector<int> adjlist[],int v,int n)
{
    queue<int> q;
    vector<bool> visited(v);
    fill(visited.begin(),visited.end(),false);
    cout<<"BFS : "<<endl;
    q.push(n);

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        cout<<temp<<endl;
        visited[temp]=true;

        for(int i=0;i<adjlist[temp].size();i++)
        {
            if(visited[adjlist[temp][i]]==false)
            q.push(adjlist[temp][i]);
        }
    }
}

int main()
{
    int v;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    vector<int> adjlist[v];

    connectEdge(adjlist);

    BFS(adjlist,v,2);
}
