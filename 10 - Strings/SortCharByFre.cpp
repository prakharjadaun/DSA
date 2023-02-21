#include<unordered_map>
using namespace std;
#include<string>
#include<climits>
class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> hashmap;
        for(char ch : s)
        {
            hashmap[ch]++;
        }    
        int mx_fre = INT_MIN;
        char ch;
        string ans="";
        while(hashmap.size()!=0)
        {
            mx_fre = INT_MIN;
            for(auto temp : hashmap)
            {
                if(temp.second > mx_fre)
                {
                    mx_fre = temp.second;
                    ch = temp.first;
                }
            }
            // cout<<ch<<endl;
            hashmap.erase(ch);

            for(int i=0;i<mx_fre;i++)
            {
                ans += ch;
            }
        }
        return ans;
    }
};