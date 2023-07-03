#include<vector>
using namespace std;

class Solution {
public:
    void DFS(int i,int j, int m, int n,vector<vector<int>> &grid)
    {
        //checking whether the indices are following the constraints
        if(i<0 || j<0 || i==m || j==n)
            return;
        
        //checking if the grid is sea cell, if yes then return
        if(grid[i][j]==0)
            return;
        
        //flip the land cell to sea cell
        grid[i][j]=0;

        //perform DFS traversal on its 4-directionally adjacent cells
        DFS(i-1,j,m,n,grid);
        DFS(i+1,j,m,n,grid);
        DFS(i,j+1,m,n,grid);
        DFS(i,j-1,m,n,grid);
    }
    //we need to find the land cells which do not lead to end of the matrix
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        //we will store the boundary land cells 
        vector<pair<int,int>> boundaryOne;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1 && grid[i][j]==1)
                    boundaryOne.push_back({i,j});
            }
        }    

        //now through DFS traversal we will flip all the land cell to sea cell those who connect to the boundary
        for(auto temp : boundaryOne)
        {
            DFS(temp.first,temp.second,m,n,grid);
        }

        //in the end we will remain with all the land cells that do not lead to the boundary 
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};