#include<climits>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end(),greater<>());
        }

        int ans = 0;

        for(int i=0;i<grid[0].size();i++)
        {
            int temp = INT_MIN;
            for(int j=0;j<grid.size();j++)
            {
                temp = max(temp,grid[j][i]);
            }
            ans += temp;
        }
        return ans;
    }
};