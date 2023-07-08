#include<vector>
using namespace std;

class Solution {
  public:
    //Approach : 
    //1. consider that there will be different components
    //2. and there is a condition that though may be nodes form a circle but there won't be any loop
    //3. We will use two vectors
    //   - visited vector
    //   - pathvisited vector (when we backtrack, we mark that node as unvisited as we are moving back in path)
    
    bool DFS(int node, vector<int> adj[], vector<int> &vis,vector<int> &pathvis)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                if(DFS(it,adj,vis,pathvis))
                    return true;
            }
            else if(pathvis[it]==1)
                return true;
        }
        
        pathvis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
       vector<int> vis(V,0);
       vector<int> pathvis(V,0);
       //will iterate on each node (there might be a case that the graph is not fully connected)
       for(int i=0;i<V;i++)
       {
           if(DFS(i,adj,vis,pathvis))
                return true;
       }
       
       return false;
    }
};