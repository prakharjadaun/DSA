#include<vector>
using namespace std;
class Solution {
    //backtracking approach
    void dfs(vector<vector<int>> graph,vector<int> &temp,vector<vector<int>> &ans,int cur)
    {
        temp.push_back(cur);
        if(cur == graph.size()-1)
            ans.push_back(temp);
        else
        {
            for(auto it: graph[cur])
                dfs(graph,temp,ans,it);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(graph,temp,ans,0);
        return ans;
    }
};