#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        bool flag = false;
        if(intervals.size()==0)
            return {newInterval};
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0] > newInterval[0])
            {
                intervals.insert(intervals.begin()+i,newInterval);
                flag = true;
                break;
            }
        }    

        if(!flag)
            intervals.push_back(newInterval);

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++)
        {
            if(ans.back()[1] >= intervals[i][0])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;

    }
};