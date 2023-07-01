#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

void addEdges(vector<pair<int,int>> adjlist[])
{
    int e,u,v,w;
    cout<<"Enter the number of edges: ";
    cin>>e;

    for(int i=0;i<e;i++)
    {   
        cout<<"Enter u : ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;
        cout<<"Enter the weight: ";
        cin>>w;

        adjlist[u].push_back({v,w});
    }   
}

void BFS(vector<pair<int,int>> adjlist[],int v)
{
    vector<bool> check(v,false);
    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        if(check[temp]==false)
        {
            cout<<temp<<endl;
            check[temp]=true;
            
        }
        for(int i=0;i<adjlist[temp].size();i++)
            {
                if(check[adjlist[temp][i].first]==false)
                    q.push(adjlist[temp][i].first);
            }
    }
}

void DFS(vector<pair<int,int>> adjlist[],int v)
{
    vector<bool> check(v,false);
    stack<int> st;

    st.push(0);

    while(!st.empty())
    {
        int temp = st.top();
        st.pop();

        if(check[temp]==false)
        {   
            check[temp]=true;
            cout<<temp<<endl;
        }

        for(int i=0;i<adjlist[temp].size();i++)
        {
            if(check[adjlist[temp][i].first]==false)  
                st.push(adjlist[temp][i].first);
        }
    }
}


//our main motive is to store the weights of the graphs and their connections in the adjacency list
int main()
{
    int v;
    //first take the input the number of vertices
    cout<<"Enter the number of vertices: ";
    cin>>v;

    //we will store the that vertex and the weight to that vertex in pairs
    vector<pair<int,int>> adjlist[v];
    addEdges(adjlist);
    BFS(adjlist,v);
    DFS(adjlist,v);
}