#include<iostream>
#include<vector>
using namespace std;

//memoization
//time complexity: O(n)
//space complexity: O(n) + O(n) //one for memoization and one for stack space
int Fibonacci(int n,vector<int> &dp)
{
    if(n<=1)
        return n;
    
    if(dp[n]!=-1)
        return dp[n];
    
    return dp[n] = Fibonacci(n-1,dp) + Fibonacci(n-2,dp);
}

int main()
{
    // 0 1 1 2 3
    int n = 4;
    vector<int> dp(n+1,-1);
    cout<<Fibonacci(n,dp)<<endl;
}