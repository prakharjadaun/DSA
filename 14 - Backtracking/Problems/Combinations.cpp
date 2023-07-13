#include<vector>
using namespace std;
class Solution {
public:
    void backtrack(vector<vector<int>> &res,int cur, int n,int k,vector<int> comb)
    {
        if(k==0)
        {
            res.push_back(comb);
            return;
        }

        if(cur<=n-k)
            backtrack(res,cur+1,n,k,comb);
        comb.push_back(cur);
        backtrack(res,cur+1,n,k-1,comb);
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> res;
        backtrack(res,1,n,k,vector<int>());
        return res;
    }
};