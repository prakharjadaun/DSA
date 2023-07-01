#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addEdges(vector<pair<int,int>> adjlist[])
{
    int e,u,v,w;
    cout<<"Enter the number of edges : ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        cout<<"enter u : ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;
        cout<<"Enter w : ";
        cin>>w;

        adjlist[u].push_back({v,w});
    }
}

void BFS(int idx, vector<bool> &visited,vector<pair<int,int>> adjlist[])
{
    queue<int> q;
    q.push(idx);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        if(!visited[temp])
        {
            visited[temp] = true;
        }
        for(int i=0;i<adjlist[temp].size();i++)
        {
            if(visited[adjlist[temp][i].first]==false)
                q.push(adjlist[temp][i].first);
        }
    }
}


int ConnectedComponentTraversal(vector<pair<int,int>> adjlist[],vector<bool> &visited,int v)
{
    int ans = 0;
    for(int i=0;i<visited.size();i++)
    {
        if(!visited[i])
        {
            BFS(i,visited,adjlist);
            visited[i] = true;
            ans++;
        }
    }
    return ans;
}



int main()
{
    int v;
    cout<<"Enter the vertices: ";
    cin>>v;
    
    vector<pair<int,int>> adjlist[v];
    addEdges(adjlist);

    vector<bool> visited(v,false);

    cout<<ConnectedComponentTraversal(adjlist,visited,v)<<endl;
}