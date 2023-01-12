#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        int ans = 0;
        for(int i=0;i<items.size();i++)
        {
            if(items[i][0]==ruleValue && ruleKey =="type")
            ans++;
            else if(items[i][1]==ruleValue && ruleKey=="color")
            ans++;
            else if(items[i][2] == ruleValue && ruleKey=="name")
            ans++;
        }    
        return ans;
    }
};