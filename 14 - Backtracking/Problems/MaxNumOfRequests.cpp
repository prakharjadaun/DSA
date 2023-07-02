#include<vector>
using namespace std;
class Solution {
    int ans = 0;
public:
    void helper(int start,vector<vector<int>> &req,vector<int> &indegree,int n, int count)
    {
        if(start == req.size())
        {
            for(int i=0;i<n;i++)
            {
                if(indegree[i]!=0)
                    return;
            }
            ans = max(ans,count);
            return;
        }

        //take
        indegree[req[start][0]]--;
        indegree[req[start][1]]++;
        helper(start + 1, req, indegree,n, count+1);

        //not take
        indegree[req[start][0]]++;
        indegree[req[start][1]]--;
        helper(start+1,req,indegree,n,count);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) 
    {
        vector<int> indegree(n,0);
        helper(0,requests,indegree,n,0);
        return ans;
    }
};