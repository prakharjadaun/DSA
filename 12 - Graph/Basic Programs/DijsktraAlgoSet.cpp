#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st;
        vector<int> dis(V,1e9);
        st.insert({0,S});
        dis[S] = 0;
        
        while(!st.empty())
        {
            auto it = *(st.begin());
            int wt = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto temp: adj[node])
            {
                int adjnode = temp[0];
                int edgeWt = temp[1];
                
                if(wt + edgeWt < dis[adjnode])
                {
                    //this condition makes sets more efficient
                    //because they save us from iterating the route which won't give us the best path
                    if(dis[adjnode]!=1e9)   
                        st.erase({dis[adjnode],adjnode});
                    dis[adjnode] = wt + edgeWt;
                    st.insert({dis[adjnode],adjnode});
                }
            }
        }
        return dis;
    }
};