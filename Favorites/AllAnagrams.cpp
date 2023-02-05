#include<vector>
using namespace std;
#include<string>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> ans;
        if(p.size() > s.size())
            return ans;
        
        vector<int> pFre(26,0);
        vector<int> sFre(26,0);

        for(int i=0;i<p.size();i++)
        {
            pFre[p[i]-'a']++;
            sFre[s[i]-'a']++;
        }

        if(pFre == sFre)
            ans.push_back(0);
        
        for(int i=p.size();i<s.size();i++)
        {
            sFre[s[i-p.size()]-'a']--;
            sFre[s[i]-'a']++;

            if(sFre == pFre)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};