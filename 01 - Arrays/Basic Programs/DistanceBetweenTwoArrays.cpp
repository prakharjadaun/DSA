#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
//question explanation: 
//https://leetcode.com/problems/find-the-distance-value-between-two-arrays/solutions/1913945/problem-description-explained-in-simple-english/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int ans = arr1.size();
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++)
        {
            for(int j=arr2.size()-1;j>=0;j--)
            {
                if(abs(arr1[i] - arr2[j])<=d)
                {
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};