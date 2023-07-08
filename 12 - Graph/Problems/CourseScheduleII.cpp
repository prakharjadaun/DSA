#include<vector>
#include<queue>
using namespace std;
class Solution {
public:

    vector<int> findOrder(int v, vector<vector<int>>& mat) 
    {
        vector<int> adj[v];
        vector<int> res;
        vector<int> indeg(v,0);
        queue<int> q;
        //converting that mat to adjlist
        for(int i=0;i<mat.size();i++)
        {
            adj[mat[i][1]].push_back(mat[i][0]);
        }


        //getting the indegree
        for(int i=0;i<v;i++)
        {
            for(auto it: adj[i])
                indeg[it]++;
        }
        //pushing the nodes with indegree 0 in the queue
        for(int i=0;i<v;i++)
            if(indeg[i]==0)
                q.push(i);

        //performing DFS
        while(!q.empty())
        {
            //getting the current node
            int node = q.front();
            q.pop();

            //putting the node in the result vector
            res.push_back(node);
            
            //decreasing the indeg of all its adjacent nodes
            for(auto it: adj[node])
            {
                indeg[it]--;
                //if indegree becomes 0, push into the queue
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        //if res size is not equal to v, just remember that all nodes are not visited
        //return empty vector
        if(res.size()!=v)
            return {};
        return res;
    }
};