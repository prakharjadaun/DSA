#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    vector<int> res;
    void DFS(int node,vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for(auto it: adj[node])
        {
            if(!vis[it])
                DFS(it,adj,vis);
        }
        
        res.insert(res.begin(),node);
    }
	public:
	//Function to return list containing vertices in Topological order. 


    //topological sort: linear ordering of vertices such that if there is an edge between u and v, u appears before V in that ordering
    //DAG : directed acyclic graph
    //acyclic because when there is a cycle then you cannot have an ordering
    //directed: because when it is undirected then you cannot decide which node to consider in the ordering
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            DFS(i,adj,vis);
	    }
	    return res;
	}
};