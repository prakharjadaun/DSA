#include<vector>
using namespace std;

class Solution {
public:
    void eraseIslandDFS(int i,int j, vector<vector<char>> &grid)
    {
        //if the index i and j are exceeding or grid is having '0' we return
        if(i==grid.size() || j==grid[0].size() || i<0 || j<0 || grid[i][j]=='0')
            return;
        
        grid[i][j]='0';
        eraseIslandDFS(i-1,j,grid);
        eraseIslandDFS(i+1,j,grid);
        eraseIslandDFS(i,j-1,grid);
        eraseIslandDFS(i,j+1,grid);
    }   
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='0')
                    continue;
                res++;
                //function to perform DFS, whenever we visit we erase all the islands (1's connected)
                eraseIslandDFS(i,j,grid);
            }
        }
        return res;
    }
};