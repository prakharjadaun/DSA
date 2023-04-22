#include <bits/stdc++.h> 
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>
#include<algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //definnning a adjacency list using unordered_map which will store elements along with its weights 
    unordered_map<int,list<pair<int,int>>> adj;

    //filling the adjacency list
    for(int i=0;i<g.size();i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //definning three vectors 
    //to store the min weight 
    vector<int> key(n+1,INT_MAX);
    //to mark that the node is visited
    vector<bool> mst(n+1,false);
    //to store the parent of that node (to which it will be connected to get the mst)
    vector<int> parent(n+1,-1);

    //assigning weight 0 to the first element of that graph
    key[1] = 0;
    
    //iterating through the all edges
    for(int i=1;i<n;i++)
    {
        //assignning max value initially to the mini 
        int mini = INT_MAX;
        //var u to store the index of that min element in the keys
        int u;

        //find the mini node
        for(int v = 1;v<=n;v++)
        {
            if(mst[v]==false && key[v]< mini)
            {
                mini = key[v];
                u = v;
            }
        }

        //marking that uth index visited
        mst[u] = true;

        //check its adjacent node
        for(auto it: adj[u])
        {
            //getting its adjacent nodes and its weight
            int v = it.first;
            int w = it.second;
            //checking whether that node is visited or not
            //if it is visited that the weight is less or not
            if(mst[v]==false && w<key[v])
            {
                //if it is not assigned a min weight, then we assign a new min weight and change the parent of that v to u
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int,int>,int>> res;
    //storing the result
    for(int i=2;i<=n;i++)
    {
        res.push_back({{parent[i],i},key[i]});
    }
    //returning the result
    return res;
}
