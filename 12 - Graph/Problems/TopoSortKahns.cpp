#include<vector>
#include<queue>
using namespace std;
class Solution
{
	public:
    //Kahn's algorithm: it is perform topological sort using BFS algo
    //we will have a array of indegree
    //and the one which will have indegree of 0, we will push them into queue
    //when we pop out the element, we decrease the indegree for all the adjacent nodes
    //if the indegree for any connected nodes becomes 0, then push them into queue
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<int> indegree(V,0);
        //computing the indegree first
	    for(int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	            indegree[it]++;
	    }
	    
        //push the element having indegree as 0
	    queue<int> q;
	    for(int i=0;i<V;i++)
	        if(indegree[i]== 0)
	            q.push(i);
	            
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                //then push the element into the queue whose indegree becomes 0
                if(indegree[it]==0) 
                    q.push(it);
            }
        }
        //return the result vector
        return res;
	}
};