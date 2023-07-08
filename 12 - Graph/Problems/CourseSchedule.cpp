#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& mat) 
    {
        vector<int> adj[v];
        queue<int> q;
        vector<int> indegree(v,0);
        int count = 0;
        for(int i=0;i<mat.size();i++)
        {
            adj[mat[i][1]].push_back(mat[i][0]);
        }    

        for(int i=0;i<v;i++)
        {
            for(auto it: adj[i])
                indegree[it]++;
        }

        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
    
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) 
                    q.push(it);
            }
        }
        return count == v;
    }
};