#include<unordered_map>
#include<vector>
#include<climits>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) 
    {
        map<int,int> hashmap;
        for(int n : nums)
        {
            if(n % 2==0)
                hashmap[n]++;
        }    
        if(hashmap.size()==0)
            return -1;
        int max_fre = INT_MIN;
        for(auto temp : hashmap)
        {
            if(temp.second > max_fre)
            {
                max_fre = temp.second;
            }
        }

        set<int> hashset;
        set<int>::iterator it;
        for(auto temp : hashmap)
        {
            if(temp.second == max_fre)
            {
                hashset.insert(temp.first);
            }
        }
        it = hashset.begin();
        return *it;
    }
};