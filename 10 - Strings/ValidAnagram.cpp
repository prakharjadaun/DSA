#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> y,z;
        for(int i=0;i<s.size();i++)
        {
            y[s[i]]++;
        }    
        for(int i=0;i<t.size();i++)
        {
            z[t[i]]++;
        }
        if(y.size()!=z.size())
            return false;
        for(auto temp : y)
        {
            if(z.find(temp.first)==z.end())
                return false;
            if(z[temp.first] != temp.second)
                return false;
        }
        return true;
    }
};