#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    bool checkVowel(char ch)
    {
        if(ch>=65 && ch<=90)
            ch = ch + 32;
        switch(ch)
        {
            case 'a':
            case 'i':
            case 'e':
            case 'o':
            case 'u':
                return true;
            default: 
                return false;
        }
        return false;
    }
    string toGoatLatin(string sentence) 
    {
        stringstream s(sentence);
        string word;
        string res;
        string last = "a";
        string mid = "ma";
        while(s>>word)
        {
            if(checkVowel(word[0]))
            {
                word+= mid;
                word+= last;
            }
            else
            {
                char ch = word[0];
                word.erase(word.begin());
                word += ch;
                word += mid;
                word += last;
            }
            res += word;
            res += " ";
            last += "a";
        }    
        res.pop_back();
        return res;
    }
};