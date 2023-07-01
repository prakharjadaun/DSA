#include<iostream>
#include<vector>
using namespace std;
class Solution {
public: 

    //code to perform Depth first search
    void DFS(int node, vector<int> adjlist[],vector<bool> &vis)
    {
        vis[node] = true;
        for(auto it: adjlist[node])
            if(!vis[it])
                DFS(it,adjlist,vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int v = isConnected.size();
        vector<int> adjlist[v];

        //first converting the matrix to list
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }    

        int res = 0;
        //then iterate to each of the index (vertices) to check whether it has been visited or not
        vector<bool> vis(v,false);
        for(int i=0;i<v;i++)
        {
            //if not, then increment res (indicating that a connected component starts here)
            if(!vis[i])
            {
                res++;
                //visit all the nodes that are been connected
                DFS(i,adjlist,vis);
            }
        }
        //whenever the res increments, that indicates that another province starts
        //lastly, return the total provinces
        return res;
    }
};