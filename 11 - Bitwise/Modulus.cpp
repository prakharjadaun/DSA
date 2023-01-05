#include<bits/stdc++.h>
using namespace std;
int mod(int x,int y)
{
    //example 
    //10 % 2 = 0 (remainder is 0 when 10 is divided by 2)
    //1010 % 10 = 0
    //simply we can just decrement the second number by 1 and perform bitwise & with the first number
    return x & (y-1);
}

int main()
{
    int x = 4;
    int y = 6;
    cout<<mod(10,2)<<endl;
}