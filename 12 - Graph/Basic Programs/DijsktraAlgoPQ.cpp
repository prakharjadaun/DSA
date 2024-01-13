
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // create a min heap with help of priority queue storing pair of distance and nodes
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        //creating a distance vector
        vector<int> dis(V,1e9);
        dis[S] = 0;
        //pushing the source vertex with distance 0 to the min heap
        pq.push({0,S});
        
        while(!pq.empty())
        {
            //get the node 
            auto node = pq.top().second;
            //get the current dist
            auto d = pq.top().first;
            pq.pop();
            
            //iterate to adjacent nodes
            for(auto it: adj[node])
            {
                int wt = it[1];
                int adjnode = it[0];
                
                //if the d and adjnode's dist is less than the corresponding distance in distance vecor
                //update it
                if(d + wt < dis[adjnode])
                {
                    dis[adjnode] = d + wt;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        //finally return the distance vector
        return dis;
    }
};
