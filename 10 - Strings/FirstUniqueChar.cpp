#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) 
    {
        int ans=-1;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }    
        
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==1)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};