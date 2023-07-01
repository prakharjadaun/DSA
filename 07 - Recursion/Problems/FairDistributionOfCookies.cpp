#include<climits>
#include<vector>
#include<iostream>
using namespace std;
/*
We use a k length vector, to store the sum of cookies for each child.
It is like placing each element in k different subsets.
So we assign each and every bag of cookies to different subsets using backtracking and if all are distributed, we check for the maximum element in that case, and update our ans according to it.
let n = size of given array
As for each element we have k subset choices and there are total of n elements, so Time complexity : O(k^n)

*/
class Solution {
    int res = INT_MAX;
    void solve(int start,vector<int> &nums,vector<int> &v, int k)
    {
        if(start == nums.size())
        {
            int maxm = INT_MIN;
            for(int i=0;i<k;i++)
                maxm = max(maxm,v[i]);

            res = min(res,maxm);
            return;
        }

        for(int i=0;i<k;i++)
        {
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {
        int n = cookies.size();
        vector<int> v(k,0);
        solve(0,cookies,v,k);
        return res;
    }
};