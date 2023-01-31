#include<vector>
using namespace std;
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(i==j && grid[i][j]==0)
                    return false;
                if(i+j==grid.size()-1 && grid[i][j]==0)
                    return false;
                if(i!=j && i+j!=grid.size()-1 && grid[i][j]!=0)
                    return false;
            }
        }    
        return true;
    }
};