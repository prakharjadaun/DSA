#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        long long res = 0, n = weights.size()-1;
        for(int i=0;i<n;i++)
            weights[i] += weights[i+1];

        weights.pop_back();

        sort(weights.begin(),weights.end());
        for(int i=0;i<k-1;i++)
            res+= weights[n-1-i] - weights[i];
        
        return res;
    }
};