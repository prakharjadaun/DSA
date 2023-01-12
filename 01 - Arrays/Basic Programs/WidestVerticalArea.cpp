#include<set>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        set<int> hashset;
        for(int i=0;i<points.size();i++)
        {
            hashset.insert(points[i][0]);
        }    
        if(hashset.size()==1)
        return 0;
       vector<int> temp(hashset.begin(),hashset.end());
       int ans = INT_MIN;
       for(int i=1;i<temp.size();i++)
       {
           if(temp[i]-temp[i-1] > ans)
           {
               ans = temp[i] - temp[i-1];
           }
       }
       return ans;
    }
};