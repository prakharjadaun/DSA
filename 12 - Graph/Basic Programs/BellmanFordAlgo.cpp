//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    //shorted distance from source
    //gives the distance vector for every node in N-1 iterations
    //can detect negative cycles if on Nth iterations weights are still getting updated
    //TC: quadratic [O(n2)]
    //takes more time than dijsktra but very useful when your graph contains negative edge weights
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S] = 0;
        
        for(int i=0;i<V-1;i++)
        {
            for(auto it: edges)
            {
                auto u = it[0];
                auto v = it[1];
                auto wt = it[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(auto it: edges)
        {
            auto u = it[0];
            auto v = it[1];
            auto wt = it[2];
            
            if(dist[u]!=1e8 && dist[u]+wt<dist[v])
            {
                return {-1};
            }
        }
        
        
        return dist;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends