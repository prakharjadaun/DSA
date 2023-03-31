#include<vector>
// #include<math.h>
// #include<cmath>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> num;
    Solution(vector<int>& nums) {
        num = nums;
    }
    
    vector<int> reset() 
    {
        return num;    
    }
    
    vector<int> shuffle() 
    {
        vector<int> res(num.begin(),num.end());
        for(int i=0;i<res.size()-1;i++)
        {
            int pos = rand() % (res.size()-i);
            swap(res[i+pos], res[i]);
        }    
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */