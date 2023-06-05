#include<iostream>
using namespace std;

int minSteps(int n)
{
    int ans = 0;
    while(n!=0)
    {
        if(n%2==0)
            n/=2;
        else
            n-=1;
        ans++;
    }
    return ans;
}

int main()
{
    cout<<minSteps(12)<<endl;
}