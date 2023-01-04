#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        //converting the string s (sentence) into stringstream
        stringstream ss(s);

        string str;
        //extracting the words from the stringstream and storing them into string str
        while(ss>>str)
        {

        }    

        //lastly str contains the last word of the sentence and hence return its size
        return str.size();
    }
};