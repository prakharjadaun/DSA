class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        // 2 ^ 0 = 1 = 1
        // 2 ^ 1 = 2 = 10
        // 2 ^ 2 = 4 = 100
        // 2 ^ 3 = 8 = 1000
        //a number is a power of 2 if it has only 1 set bit
        //if we perform & operation between the number (which is a power of 2) and the number less than 1, it yields 0 
        // 4 -> 100
        // 3 -> 010
        // & -> 000

        //also 0 and number less than 0 are not among power of 2
        
        if(n<=0)
        return false;
        return n & (n-1)? false:true;
    }
};