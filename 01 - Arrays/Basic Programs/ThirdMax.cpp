#include <iostream>
#include<vector>
#include<set>
using namespace std;
// time : O(n)
// space : O(1)
int thirdMax(vector<int> &nums)
{
    set<int, greater<int>> hashset(nums.begin(), nums.end());
    set<int>::iterator it;
    if (hashset.size() < 3)
        return *(hashset.begin());
    for (int i = 0; i < 2; i++)
    {
        hashset.erase(hashset.begin());
    }
    it = hashset.begin();
    return *it;
}
