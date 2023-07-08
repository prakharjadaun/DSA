#include<queue>
#include<vector>
#include<algorithm>
#include<numeric>     //for accumulate()
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        //Intuition : Kahn's algo approach
        //we will visit each node like topological sort
        //if the node is having a cycle, then its indegree won't get 0 when we actually need to push that into the queue
        //and because of this not all nodes would be visited
        //lastly i will be finding the sum of the visited array whether it is equal to the number of nodes
        //if not return true that a cycle exist
        vector<int> indegree(V,0);
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
            if(indegree[i]==0)
                q.push(i);
                
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            vis[node] = 1;
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        return accumulate(vis.begin(),vis.end(),0) == V? false: true;
    }
};