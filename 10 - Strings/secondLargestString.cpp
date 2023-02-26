#include<set>
#include<string>
using namespace std;
class Solution {
public:
    int secondHighest(string s) 
    {
        set<int,greater<int>> hashset; 
        set<int,greater<int>>::iterator it;  
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=48 && s[i]<=57)
                hashset.insert(s[i]-'0');
        } 

        if(hashset.size()<=1)
            return -1;
        // hashset.erase(hashset.begin());
        it = hashset.begin();
        it++;
        return *it;

    }
};