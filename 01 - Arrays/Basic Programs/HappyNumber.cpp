
class Solution {
public:

    int update(int n)
    {
        int res = 0;
        while(n!=0)
        {
            int rem = n%10;
            res = res + (rem*rem);
            n = n/10;
        }
        return res;
    }
    bool isHappy(int n) 
    {
        if(n==1 || n==7)
        return true;

        while(n>9)
        {
            n = update(n);
            
            if(n==1 || n==7)
            return true;
        }
        return false;
    }
};