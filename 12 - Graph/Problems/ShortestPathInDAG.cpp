#include<vector>
#include<stack>
using namespace std;
class Solution {
  public:
    void DFS(int node, vector<pair<int,int>> adj[],vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(!vis[it.first])
                DFS(it.first,adj,vis,st);
        }
        
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        // code here
        //1. creating the adjacency list
        vector<pair<int,int>> adj[N];
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        //2. finding the toposort
        stack<int> st;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++)
            if(!vis[i])
                DFS(i,adj,vis,st);
                
                
        //3. do the distance thing
        vector<int> dist(N,1e9);
        dist[0]=0;
        //iterate the stack
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            //iterate on all the adjacent nodes of the current top of the stack
            for(auto it: adj[node])
            {
                int v = it.first;
                int wt = it.second;
                //if the distance[node] + distance of current node with the node is less than the distance of current node
                //update it
                if(dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }
        for(int i=0;i<N;i++)
            if(dist[i]==1e9)
                dist[i]=-1;
        
        return dist;
    }
};
