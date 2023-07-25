#include<vector>
#include<algorithm>
using namespace std;
bool compare(vector<int>& i, vector<int>& j)
{
    return i[1] < j[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {    
        sort(points.begin(),points.end(),compare);
        int ans = 0, arrow = 0;
        for(int i=0;i<points.size();i++)
        {
            if(ans == 0 || points[i][0] > arrow)
            {
                ans++;
                arrow = points[i][1];
            }
        }
        return ans;
    }
};