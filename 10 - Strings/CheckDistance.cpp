#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) 
    {
        vector<int> temp(26,0);
        for(int i=0;i<s.size();i++)
        {
            if(temp[s[i]-'a']==0)
                temp[s[i]-'a'] = i;
            else
                temp[s[i]-'a'] = i - temp[s[i]-'a'];
        }    

        for(int i=0;i<26;i++)
        {
            if(temp[i]==0)
            continue;
            if(temp[i]-1!=distance[i])
                return false;
        }
        return true;
    }
};