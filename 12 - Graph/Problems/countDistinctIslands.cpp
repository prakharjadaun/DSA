#include<vector>
#include<set>
using namespace std;

class Solution {
  public:
    void DFS(int r,int c, vector<pair<int,int>> &vec,  vector<vector<int>> &vis,vector<vector<int>>& grid,int ro, int co)
    {
        int m = grid.size();
        int n = grid[0].size();
        //checking if it following the size constraint or not and is visited or not and finally that if it contains 0, then we return
        if(r<0 || c<0 || r==m || c==n || vis[r][c] || grid[r][c]==0)
            return;
        
        //marking that node visited
        vis[r][c] = 1;
        //pusing that cell to the vec 
        //subtracting the base row and col indices
        vec.push_back({r-ro,c-co});
        
        //performing DFS to the 4-directionally adjacent cells of the grid
        DFS(r-1,c,vec,vis,grid,ro,co);
        DFS(r+1,c,vec,vis,grid,ro,co);
        DFS(r,c-1,vec,vis,grid,ro,co);
        DFS(r,c+1,vec,vis,grid,ro,co);
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        //maintaining a visited vector whether that cell is covered or not
        vector<vector<int>> vis(m,vector<int>(n,0));
        //maintaining a set to store the unique set
        set<vector<pair<int,int>>> hashset;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                //if a cell is unvisited and it contains 1, perform DFS   
                if(!vis[i][j] && grid[i][j]==1)
                {
                    //maintaining a vec to store the structure 
                    vector<pair<int,int>> vec;
                    DFS(i,j,vec,vis,grid,i,j);
                    //storing that vector to the set
                    hashset.insert(vec);
                }
            }
        }
        return hashset.size();
    }
};