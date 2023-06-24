#include<iostream>
#include<vector>
using namespace std;

//time complexity: O(n)
//space complexity: O(n)
int fibo(int n)
{
    //dynamic approach
    vector<int> dp(n+1,0);
    if(n>1)
    {
        dp[1] = 1;
        for(int i=2;i<=n;i++)
            dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n =4;
    cout<<fibo(n)<<endl;
}