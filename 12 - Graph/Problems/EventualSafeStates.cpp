#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    bool DFS(int node, vector<int> adj[],vector<int> &vis,vector<int> &pathvis,vector<int> &check)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(vis[it]==0)
            {
                if(DFS(it,adj,vis,pathvis,check))
                {
                    check[it] = 0;
                    return true;
                }
            }
            else if(pathvis[it]==1){
                check[it]=0;
                return true;
            }
                
        }
        
        pathvis[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) 
    {
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> check(V,0);
        vector<int> safenodes;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                DFS(i,adj,vis,pathvis,check);
        }
        
        for(int i=0;i<V;i++)
        {
            if(check[i]==1)
                safenodes.push_back(i);
        }
        return safenodes;
    }
};