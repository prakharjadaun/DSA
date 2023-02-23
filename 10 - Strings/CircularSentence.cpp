#include<string>
using namespace std;
#include<sstream>
#include<vector>
class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
        if(sentence[0]!=sentence[sentence.size()-1])
            return false;

        stringstream ss(sentence);
        string word;
        vector<string> temp;
        while(ss>>word)
        {
            temp.push_back(word);
        }    

        for(int i=0;i<temp.size()-1;i++)
        {
            if(temp[i][temp[i].size()-1] != temp[i+1][0])
                return false;
        }
        return true;
    }
};