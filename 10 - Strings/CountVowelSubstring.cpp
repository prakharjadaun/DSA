#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            return true;
        return false;
    }
    int countVowelSubstrings(string word) 
    {
        if(word.size()<5)
            return 0;
        int ans = 0;
        vector<bool> vowels(26,false),temp(26,false);
        vowels['a'-'a']=true;
        vowels['e'-'a']=true;
        vowels['i'-'a']=true;
        vowels['o'-'a']=true;
        vowels['u'-'a']=true;
        
        for(int i=0;i<=word.size()-5;i++)
        {   
            if(!isVowel(word[i]))
                continue;
            for(int j=i;j<word.size();j++)
            {
                temp[word[j]-'a'] = true;
                if(temp == vowels)
                    ans++;
            }
            fill(temp.begin(),temp.end(),false);
        }
        return ans;
    }
};