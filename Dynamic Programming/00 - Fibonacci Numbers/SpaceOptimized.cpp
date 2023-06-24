#include<iostream>
#include<vector>
using namespace std;

//time complexity: O(n)
//space complexity: O(1)
int fibo(int n)
{
    //dynamic approach
    vector<int> dp(2);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++)
        dp[i%2] = dp[(i-1)%2] + dp[(i-2)%2];
    
    return dp[n%2];
}

int main()
{
    int n =4;
    cout<<fibo(n)<<endl;
}