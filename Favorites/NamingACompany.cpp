#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) 
    {
        unordered_set<string> hashset[26];
        for (auto& s: ideas)
            hashset[s[0] - 'a'].insert(s.substr(1));
        long long res = 0;
        for(int i = 0; i < 26; ++i)
        {
            for(int j = i + 1; j < 26; ++j) 
            {   
                long long c1 = 0L, c2 = 0L;
                for (auto& c: hashset[i])
                    if (!hashset[j].count(c)) c1++;
                for (auto& c: hashset[j])
                    if (!hashset[i].count(c)) c2++;
                res += c1 * c2;
            }
        }
        return res * 2;
    }
};