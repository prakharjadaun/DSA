#include<unordered_map>
using namespace std;
#include<string>
class Solution {
public:
    string decodeMessage(string key, string message) 
    {
        unordered_map<char,char> m;
        char ch = 'a';
        string ans = "";
        for(int i=0;i<key.size();i++)
        {
            if(key[i]==' ')
            continue;
            if(m.find(key[i])==m.end())
            {
                m[key[i]]=ch++;
            }
        }    

        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
            {
                ans += " ";
                continue;
            }

            ans += m[message[i]];
        }
        return ans;
    }
};