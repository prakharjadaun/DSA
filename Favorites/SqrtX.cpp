class Solution {
public:
    //integet newton method
    int mySqrt(int x) 
    {
        long long r = x;
        while(r*r > x)
        {
            r = (r + x/r)/2;
        }    
        return r;
    }
};