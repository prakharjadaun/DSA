#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        //first perform the xor operation between two numbers 
        // 10 -> 01010
        // 20 -> 10100
        //xor -> 11110
        //the count of set bits in xor tells us that these number of bits are needed to be changed to convert into b
        int res = (a ^ b);
        
        // return __builtin_popcount(res);
        // __builtin_popcount(res) returns the number of set bits in a number (even for long long). faster than O(n) times 

        int count = 0;
        cout<<"RES : "<<res<<endl;
        while(res>0)
        {
            if((res & 1) == 1)
            count++;

            res = res>>1;
        }
        return count;
        

    }
};

int main()
{
    Solution sol;
        //01010
    int a = 10;
        //10100
    int b = 20;

    cout<<sol.countBitsFlip(a,b)<<endl;
}