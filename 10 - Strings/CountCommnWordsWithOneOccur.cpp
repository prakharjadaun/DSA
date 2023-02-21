#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) 
    {
        unordered_map<string,int> hashmap1,hashmap2;
        int ans = 0;
        for(string s: words1)
        {
            hashmap1[s]++;
        }    

        for(string s : words2)
        {
            hashmap2[s]++;
        }

        for(auto temp : hashmap1)
        {
            if(temp.second == 1 && hashmap2.find(temp.first)!=hashmap2.end() && hashmap2[temp.first]==1)
                ans++;
        }
        return ans;
    }
};