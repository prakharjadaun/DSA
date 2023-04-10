#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        unordered_set<int> hashset;
        for(int i : candyType)
            hashset.insert(i);

        int temp = candyType.size()/2;
        if(temp <= hashset.size())
            return temp;
        return hashset.size();    
    }
};