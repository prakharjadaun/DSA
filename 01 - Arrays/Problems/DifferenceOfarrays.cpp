#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s1(nums1.begin(),nums1.end()), s2(nums2.begin(),nums2.end());

        for(int i=0;i<nums2.size();i++)
        {
            if(s1.find(nums2[i])!=s1.end())
            {
                s1.erase(nums2[i]);
            }
        }    

        for(int i=0;i<nums1.size();i++)
        {
            if(s2.find(nums1[i])!=s2.end())
            {
                s2.erase(nums1[i]);
            }
        }

        vector<int> ans1(s1.begin(),s1.end()), ans2(s2.begin(),s2.end());
        vector<vector<int>> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};