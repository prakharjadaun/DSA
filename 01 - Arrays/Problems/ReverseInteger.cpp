#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    int reverse(int x) 
    {
        if(x==0)
            return 0;

        int ans = 0;
        int pop;
        while(x!=0)
        {
            //getting the least significant digit
            pop = (x % 10);
            //checking the overflow condition
            if(ans > ((INT_MAX)/10) && x/10!=0)
                return 0;
            if(ans < ((INT_MIN)/10) && x/10!=0)
                return 0;

            //adding it to the answer variable
            ans += pop;
            //again checking the limits
            if(ans > ((INT_MAX)/10) && x/10!=0)
                return 0;
            if(ans < ((INT_MIN)/10) && x/10!=0)
                return 0;
            //if the number is not single digit then multiplying it with 10
            if(x/10!=0)
            ans = ans * 10;

            //dividing the original number by 10
            x = x/10;
        }
        
        return ans;
    }
};