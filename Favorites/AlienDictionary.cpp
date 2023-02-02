#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        //create a hashmap to store the increasing indices of new alphabetical order along with the numerical values
        unordered_map<int,int> hashmap;
        for(int i=0;i<order.size();i++)
        {
            hashmap[order[i]-'a'] = i;
        }    
        //then replace each character with its number assigned to it
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                words[i][j] = hashmap[words[i][j]-'a'];
            }
        }
        //then check if it is sorted or not
        return is_sorted(words.begin(),words.end());
    }
};