#include<vector>
using namespace std;
class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int first = cost[0], second = cost[1];
        int n = cost.size();
        for(int i=2;i<n;i++)
        {
            int curr = cost[i] + min(first,second);
            first = second;
            second = curr;
        }
        return min(first,second);
    }
};