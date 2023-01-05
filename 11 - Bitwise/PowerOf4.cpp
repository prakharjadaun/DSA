#include<bits/stdc++.h>
using namespace std;

bool isPowerOf4(int x)
{
    //examples : 
    // 4 raised to 1 : 4 -> 100
    // 4 raised to 2 : 16 -> 10000
    // that is number is a power of 4 if it contains only 1 set bit 
    
    //approach : we will find the set bit and upto that we will left shift our var initally assigned with 1
    //lastly we perform xor operation on number and var 
    //if it results 0, then return true
    //else false
    int temp = 1;
    while(!(x & temp))
    {
        temp <<= 1;
    }
    x = x ^ temp;
    if(x==0)
        return true;
    else 
        return false;
}
int main()
{
    int num = 16;
    isPowerOf4(num)?cout<<"True"<<endl:cout<<"False"<<endl;
}