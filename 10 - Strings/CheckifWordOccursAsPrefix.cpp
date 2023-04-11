#include<sstream>
using namespace std;
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) 
    {
        stringstream s(sentence);
        string word;
        int index = 0;
        while(s>>word)
        {
            index++;
            if(word.size()>=searchWord.size() && word.substr(0,searchWord.size())==searchWord)
                return index;
        }
        return -1;
    }
};