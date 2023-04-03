#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.rbegin(),people.rend());
        int i,j;
        for(i=0,j=people.size()-1;i<=j;i++)
        {
            if(people[i] + people[j] <= limit)
                j--;
        }
        return i;
    }
};