#include <bits/stdc++.h> 
using namespace std;
//time complexity: O(n)
//space complexity: O(n)
//but overlapping sub problems has to be handled, now move to memoization
int f(int n,vector<int> h)
{
    if(n==0)
        return 0;
    
    //find the solution with n-1 index
    int l = f(n-1,h) + abs(h[n] - h[n-1]);
    //if n is 1 then we cannot move to -2 position, so assigning max
    int r = INT_MAX;
    if(n>1)
        //if we can move to n-2, then compute the r
        r = f(n-2,h) + abs(h[n] - h[n-2]);
    //return the minimum value
    return min(l,r);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return f(n-1,heights);
}