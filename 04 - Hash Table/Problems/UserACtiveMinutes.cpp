#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        unordered_map<int,unordered_set<int>> hashmap;
        for(int i=0;i<logs.size();i++)
        {
            hashmap[logs[i][0]].insert(logs[i][1]);
        }    

        vector<int> res(k,0);
        for(auto temp : hashmap)
        {
            res[temp.second.size()-1]++;
        }
        return res;
    }
};