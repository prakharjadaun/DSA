#include<bits/stdc++.h>
using namespace std;

int addOne(int x)
{
    //lets take an example first
    // 4 -> 100 
    // if we perform xor operation with 1 
    // 100 
    //   1
    // 101 
    // we get our desired result 

    // but not everytime the lsb will contain a zero 
    // another example 
    // 27 -> 11011
    //after adding 1 we need 28 -> 11100

    //approach : if the lsb yields 1 after & with 1 we need left shift 1 as 10 and set that lsb as 0 
    // we will do until we find 0 with whom we can perform xor operation and add 1 to it

    int temp = 1;

    while(x & temp)
    {
        x = x ^ temp;
        temp = temp<<1;
    }
    x = x ^ temp;
    return x;
}

int main()
{
    int num = 3;
    cout<<addOne(num)<<endl;
}