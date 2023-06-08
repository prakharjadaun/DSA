#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();

        vector<int> dp(n+1,0);

        for(int i=1;i<=m;i++)
        {
            int prev = 0;
            for(int j=1;j<=n;j++)
            {
                int temp = dp[j];

                if(text1[i-1] == text2[j-1])
                    dp[j] = 1 + prev;
                else
                    dp[j] = max(dp[j],dp[j-1]);
                
                prev = temp;
            }
        }
        return dp[n];
    }
};