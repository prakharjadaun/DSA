#include<unordered_map>
using namespace std;
class Solution {
public:
    int rearrangeCharacters(string s, string target) 
    {
        unordered_map<char,int> hashmap;
        for(char ch : s)
        {
            hashmap[ch]++;
        }    
        bool flag = true;
        int copies = 0;
        while(true)
        {
            for(int i=0;i<target.size();i++)
            {
                if(hashmap.find(target[i])==hashmap.end())
                {
                    flag = false;
                    break;
                }
                else
                {
                    hashmap[target[i]]--;
                    if(hashmap[target[i]]==0)
                        hashmap.erase(target[i]);
                }
            }
            if(!flag)
                break;
            copies++;
        }
        return copies;
    }
};