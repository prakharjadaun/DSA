#include<unordered_map>
using namespace std;
class Solution {
public:
    int minSteps(string s, string t) 
    {
        unordered_map<char,int> hashmap1,hashmap2;

        for(char ch: s)
            hashmap1[ch]++;
        for(char ch : t)
            hashmap2[ch]++;

        if(hashmap1 == hashmap2)
            return 0;
        
        int count = 0;
        for(auto temp : hashmap1)
        {
            if(hashmap2.find(temp.first)!=hashmap2.end())
            {
                if(temp.second - hashmap2[temp.first]>0)
                    count += (temp.second - hashmap2[temp.first]);
            }
            else
            {
                count += temp.second;
            }
        }
        return count;
    }
};