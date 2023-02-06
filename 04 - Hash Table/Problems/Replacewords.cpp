#include<string>
#include<sstream>
using namespace std;
#include<vector>
#include<unordered_set>
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) 
    {
        unordered_set<string> hashset;
        bool flag = false;
        for(int i=0;i<dictionary.size();i++)
        {
            hashset.insert(dictionary[i]);
        }    

        stringstream ss(sentence);
        string ans,word,temp="";
        while(ss>>word)
        {
            flag = false;
            temp = "";
            for(int i=0;i<word.size();i++)
            {
                temp += word[i];
                if(hashset.find(temp)!=hashset.end())
                {
                    flag = true;
                    ans += temp;
                    ans+= " ";
                    break;
                }
            }
            if(flag == false)
            {
                ans+= word;
                ans+= " ";
            }
        }
        ans = ans.substr(0,ans.size()-1);
        return ans;
    }
};