#include<iostream>
#include<vector>
using namespace std;
//time complexity: O(n)
//space complexity : O(n)
long binomialCoeff(int n,int k)
{
    long res = 1;

    if(k > n-k)
        k = n-k;

    for(int i=0;i<k;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

long catalan(int num)
{   
    return binomialCoeff(2*num,num) / (num+1);
}

int main()
{
    for(int i=0;i<10;i++)
        cout<<catalan(i)<<endl;
}