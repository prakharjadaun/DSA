//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //create adjancency list
        vector<int> adj[N];
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //form a distance vector initially having infinite distance
        vector<int> dis(N,1e9);
        //queue to perform BFS
        queue<int> q;
        //insert the source vertex into the queue
        q.push(src);
        //set the distance of source vertex as 0
        dis[src] = 0;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            
            for(auto temp: adj[node])
            {
                //insert the adjacent vertex only when the distance from current node to that node is less than the distance present in the dis vector
                if(dis[node] + 1 < dis[temp])
                {
                    dis[temp] = dis[node] + 1;
                    q.push(temp);
                }
            }
        }
        
        //if any node is unreachable then set it as -1
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]==1e9)
                dis[i] = -1;
        }
        
        //return distance vector
        return dis;
    }
};

