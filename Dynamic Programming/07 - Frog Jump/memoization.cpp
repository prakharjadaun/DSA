#include <bits/stdc++.h> 
using namespace std;
//time complexity: O(n)
//space complexity: O(n) + O(n) [stack space and array space]
//no overlapping sub problems
int f(int n,vector<int> h,vector<int> &dp)
{
    if(n==0)
        return 0;

    if(dp[n]!=-1)
        return dp[n];

    int left = f(n-1,h,dp) + abs(h[n] - h[n-1]);
    int right = INT_MAX;
    if(n>1)
        right = f(n-2,h,dp) + abs(h[n] - h[n-2]);
    
    return dp[n]= min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    // Write your code here.
    return f(n-1,heights,dp);
}