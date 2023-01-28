#include<vector>
using namespace std;
#include<unordered_map>
#include<algorithm>
#include<functional>
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        vector<int> temp;
        unordered_map<int,int> m;
        vector<vector<int>> ans;
        //store the index of the score in the kth column in unordered_map and push_back the score into the vector temp
        for(int i=0;i<score.size();i++)
        {
            temp.push_back(score[i][k]);
            m[score[i][k]]=i;
        }
        //sort the vector temp 
        sort(temp.begin(),temp.end(),greater<>());
        for(int i=0;i<temp.size();i++)
        {   
            //push_back that row into the anwer vector whose index is been first 
            ans.push_back(score[m[temp[i]]]);
        }
        return ans;
    }
};