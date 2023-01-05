#include<stdint.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        //ans variable for storing the count of 1 bit
        int ans=0;
        //temporary variable set to 1
        int m = 1;
        //until n is 0, loop will continue
        while(n>0)
        {
            //if m yields 1 with the lsb of n, that means the lsb is 1, we increment ans
            if(n & m == 1)
                ans++;
            //right shifting n
            n = n>>1;
        }
        return ans;
    }
};