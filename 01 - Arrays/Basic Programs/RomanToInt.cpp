#include<unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> hashmap;
        hashmap.insert({'I',1});
        hashmap.insert({'V',5});
        hashmap.insert({'X',10});
        hashmap.insert({'L',50});
        hashmap.insert({'C',100});
        hashmap.insert({'D',500});
        hashmap.insert({'M',1000});

        int number = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i==0)
            {
                number += hashmap[s[i]];
            }
            else
            {
                if(s[i-1]=='I' && (s[i]=='X' || s[i]=='V'))
                    number = (number - 1) + (hashmap[s[i]]-1);
                else if(s[i-1]=='X' && (s[i]=='L' || s[i]=='C'))
                    number = (number - 10) + (hashmap[s[i]]-10);
                else if(s[i-1]=='C' && (s[i]=='D' || s[i]=='M'))
                    number = (number - 100) + (hashmap[s[i]]-100);
                else
                    number += hashmap[s[i]];
            }
        }
        return number; 
    }
};