#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        //getting the shape of the grid
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        //to store the {{rol,col},time}
        queue<pair<pair<int,int>,int>> q;
        //creating a visited matrix 
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        //pushing all the rotten oranges cell into the queue to perform BFS
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==2)
                    //initially for rotten oranges time will be 0
                    q.push({{i,j},0});
        
        while(!q.empty())
        {
            //pop the element
            auto r = q.front().first.first;
            auto c = q.front().first.second;
            auto t = q.front().second;
            q.pop();
            
            if(!vis[r][c])
            {
                //if not marked visited, mark it visited and store its timestamp in the ans variable
                vis[r][c] = true;
                grid[r][c] = 2;
                //timestamp of the last level marked visited will be stored in the ans variable
                ans = t;

                //check for the 4-directionally adjacent cells in the grid and store them in the queue if contains fresh rotten oranges and exists
                if(r-1>=0 && grid[r-1][c]==1)
                    q.push({{r-1,c},t+1});
                if(c-1>=0 && grid[r][c-1]==1)
                    q.push({{r,c-1},t+1});
                if(r+1<m && grid[r+1][c]==1)
                    q.push({{r+1,c},t+1});
                if(c+1<n && grid[r][c+1]==1)
                    q.push({{r,c+1},t+1});
            }
        }

        //first check whether all fresh rotten oranges be fully rotten or not, if not return -1
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    return -1;
        return ans;
    }
};