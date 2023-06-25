#include<vector>
#include<math.h>
#include<climits>
using namespace std;
//time complexity: O(n)
//space complexity : O(n)
int frogJump(int n, vector<int> &h)
{
    vector<int> dp(n,0);
    dp[0] = 0;

    for(int i=1;i<n;i++)
    {
        int left = dp[i-1] + abs(h[i] - h[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2] + abs(h[i] - h[i-2]);
        
        dp[i] = min(left,right);
    }

    return dp[n-1];
}