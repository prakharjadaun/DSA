class Solution {
public:
    long binoCoeff(int n,int k)
    {
        long res = 1;

        for(int i=0;i<k;i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        return res;
    }
    int numTrees(int n) 
    {
        return binoCoeff(2*n,n) / (n+1);
    }
};