#include<iostream>
using namespace std;

//time complexity: O(dist)
//space complexity: O(1)
int countSteps(int dist)
{
    //In previous approach, we did not need the previous value after 3. So, in this approach we would be using those storage to compute our answer.
    //we only need an array of size three
    int dp[3];

    //assigning the base cases
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    //iterating from 3 to dist (inclusive) 
    for(int i=3;i<=dist;i++)
        dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3] + dp[(i-3) % 3];
    //when we reach i=3, we would be storing the computed value at 0 because 
    // 3%3 -> 0
    // because for computing the value for i=4, we won't need the previous value stored at 0th index
    
    return dp[dist % 3];
}

int main()
{
    int dist = 4;
    cout<<countSteps(dist)<<endl;
}