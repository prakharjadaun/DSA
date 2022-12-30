#include<string>
#include<map>
#include<iostream>
using namespace std;
class Solution {
public:
    //checks whether the string ransomNote can be constructed from the letters of magazine, the frequency should also be the same
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char,int> words;
        for(char c: magazine)
        {
            words[c]++;
        }

        for(char c : ransomNote)
        {
            if(words.find(c)==words.end())
            return false;

            if(words[c]==0)
            return false;

            words[c]--;
        }

        return true;
    }
};

int main()
{
    string ransomNote = "aa", magazine = "ambala";
    Solution sol;
    cout<<sol.canConstruct(ransomNote,magazine)<<std::endl;
}