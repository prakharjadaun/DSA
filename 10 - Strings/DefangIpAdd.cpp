#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
class Solution {
public:
    string defangIPaddr(string address) 
    {
        stringstream ss(address);
        string word;
        string ans = "";
        while(getline(ss,word,'.'))
        {
            ans += word + "[.]";
        }    
        return ans.substr(0,ans.size()-3);
        // return ans;
    }
};