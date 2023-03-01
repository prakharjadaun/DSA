#include<unordered_map>
#include<iostream>
using namespace std;
#include<sstream>
class Solution {
public:
    string sortSentence(string s) 
    {
        unordered_map<int,string> hashmap;
        stringstream ss(s);
        string word;
        int size=0;
        while(ss>>word)
        {
            size++;
            int n = word[word.size()-1]-48;
            word.pop_back();
            hashmap[n]=word;
        }    

        s = "";
        for(int i=1;i<=size;i++)
        {
            s += hashmap[i];
            if(i!=size)
            s+= " ";
        }
        return s;
    }
};