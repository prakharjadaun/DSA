#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//function to connect the edges
void connectEdges(vector<int> adjlist[])
{
    int u,v,e;
    cout<<"Enter the edges : ";
    cin>>e;

    for(int i=0;i<e;i++)
    {
        cout<<"Enter u : ";
        cin>>u;
        cout<<"Enter v : ";
        cin>>v;
        adjlist[u].push_back(v);
    }
}
//function to print the depth first search traversal using adjacency list
void DFSadjlist(vector<int> adjlist[],int v,int n)
{
    vector<bool> visited(v);
    stack<int> st;
    st.push(n);
    cout<<"DFS : "<<endl;
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        cout<<temp<<" ";
        visited[temp]=true;
        for(int i=0;i<adjlist[temp].size();i++)
        {
            if(visited[adjlist[temp][i]]==false)
            st.push(adjlist[temp][i]);
        }
    }
    cout<<endl;
}
int main()
{   
    //getting the number of vertices
    int v;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    vector<int> adjlist[v];
    //connecting the edges
    connectEdges(adjlist);
    //calling the dfs traversal function
    DFSadjlist(adjlist,v,0);
}