#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    bool BFS(int src, vector<int> adj[],vector<bool> &vis)
    {
        queue<pair<int,int>> q;
        vis[src] = true;
        q.push({src,-1});

        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it: adj[node])
            {
                if(!vis[it]){
                    vis[node] = true;
                    q.push({it,node});
                }
                else if(parent != it)
                    return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(BFS(i,adj,vis))
                    return true;
            }
        }
        return false;
    }
};