#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        int arr1[101],arr2[101],arr3[101];
        fill(arr1,arr1+101,0);
        fill(arr2,arr2+101,0);
        fill(arr3,arr3+101,0);

        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            if(arr1[nums1[i]]==0)
                arr1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(arr2[nums2[i]]==0)
                arr2[nums2[i]]++;
        }


        for(int i=0;i<nums3.size();i++)
        {
            if(arr3[nums3[i]]==0)
                arr3[nums3[i]]++;
        }

        for(int i=0;i<101;i++)
        {
            if(arr1[i]+arr2[i]+arr3[i]>=2)
            ans.push_back(i);
        }
        return ans;
    }
};