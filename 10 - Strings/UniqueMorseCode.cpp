#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> hashset;
        string temp;
        for(string s : words)
        {
            temp = "";
            for(int i=0;i<s.size();i++)
            {
                temp += code[s[i]-'a'];
            }
            hashset.insert(temp);
        }
        return hashset.size();
    }
};