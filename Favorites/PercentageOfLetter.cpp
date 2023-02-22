#include<math.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int percentageLetter(string s, char letter) 
    {
        int count = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==letter)
                count++;
        }    
        // cout<<s.size()<<endl;
        return floor(((double)100/s.size())*count);
    }
};