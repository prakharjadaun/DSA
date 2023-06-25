#include <bits/stdc++.h> 
using namespace std;
//time complexity : O(n)
//space complexity : O(1)
int frogJump(int n, vector<int> &h)
{
    vector<int> dp(2,0);
    dp[0] = 0;


    for(int i=1;i<n;i++)
    {
        int left = dp[(i-1)%2] + abs(h[i] - h[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[(i-2)%2] + abs(h[i] - h[i-2]);
        
        dp[i%2] = min(left,right);
    }

    return dp[(n-1)%2];
}