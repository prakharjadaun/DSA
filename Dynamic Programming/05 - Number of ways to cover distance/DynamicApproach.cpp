#include<iostream>
using namespace std;

//time complexity: O(dist)
//space complexity: O(dist)
int countSteps(int dist)
{
    //create an array of size dist+1
    int dp[dist+1];

    //we have got three base cases
    //1. assign dp[0] = 1
    dp[0] = 1;

    //2. if 1st and 2nd index exists, then assign 1 and 2
    if(dist>=1)
        dp[1] = 1;
    if(dist>=2)
        dp[2] = 2;
    
    //iterate from 3 to dist (inclusive), and assign dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
    for(int i=3;i<=dist;i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    //return dp[dist]
    return dp[dist];
}

int main()
{
    int dist = 4;
    cout<<countSteps(dist)<<endl;
}