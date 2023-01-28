#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    map<int,int> m;

    void iterate(vector<vector<int>> item)
    {
        for(int i=0;i<item.size();i++)
        {
            m[item[i][0]] += item[i][1];
        }
    }
    
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        iterate(items1);
        iterate(items2);

        vector<vector<int>> res;
        for(auto temp : m)
        {
            res.push_back({temp.first,temp.second});
        }
        return res;
    }
};