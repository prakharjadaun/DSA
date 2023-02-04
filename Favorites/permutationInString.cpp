#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    bool areEqual(vector<int> a,vector<int> b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
            return false;
        vector<int> fre1(26,0),fre2(26,0);
        for(auto ch : s1)
            fre1[ch-'a']++;
        
        int i=0,j=0;
        while(j<s2.size())
        {
            fre2[s2[j]-'a']++;

            if(j-i+1 == s1.size())
            {
                if(areEqual(fre1,fre2))
                return true;
            }
            if(j-i+1 < s1.size())
            j++;
            else
            {
                fre2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};