#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        unordered_map<char,int> fre,temp;
        int ans = 0;
        bool flag;
        for(char ch : chars)
        {
            fre[ch]++;
        }    

        for(int i=0;i<words.size();i++)
        {
            temp = fre;
            flag = true;
            for(int j=0;j<words[i].size();j++)
            {
                if(temp.find(words[i][j])==temp.end())
                {
                    flag = false;
                    break;
                }
                else
                {
                    temp[words[i][j]]--;
                    if(temp[words[i][j]]==0)
                        temp.erase(words[i][j]);
                }
            }
            if(flag)
            ans = ans + words[i].size();
        }
        return ans;
    }
};