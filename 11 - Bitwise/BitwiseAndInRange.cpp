#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        //the range is inclusive 
        //we have to return bitwise and of each number 
        //lets say range is [5,7]   
        // 5 -> 101
        // 7 -> 111
        // 4 -> 100

        //2 -> 010
        //4 -> 100
        //

        // n = 5
        // n = n & 6
        // n = n & 7

        //1. initalize ans variable with left 
        //2. iterate the loop from left + 1 until 'right' inclusive 
        //3. return ans 


        if(left==right)
        return left;

        /*
        // this logic is correct but do not works for big ranges 
        int ans = left;
        for(int i=left+1;i<=right;i++)
        {
            ans = ans & i;
        }
        return ans;
        */

       //we here right shifts the both the numbers by 1 until both becomes equal
       //and counts the number of right shifts operations
       //lastly we left shifts the left number with the number of counts

        int temp = 0;
        while(left!=right)
        {
            left = left>>1;
            right = right>>1;
            temp++;
        }
        return left<<temp;
    }
};

int main()
{
    Solution sol;
    cout<<sol.rangeBitwiseAnd(1,2147483647)<<endl;
}