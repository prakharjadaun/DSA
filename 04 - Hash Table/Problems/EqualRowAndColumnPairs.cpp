#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int count = 0;
        vector<vector<int>> col(grid.size());
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
                col[i].push_back(grid[j][i]);
        }
       

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i] == col[j])
                    count++;
            }
        }
        return count;
    }
};