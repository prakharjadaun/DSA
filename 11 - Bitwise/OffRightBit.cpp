#include<bits/stdc++.h>
using namespace std;
int TurnOffRightBit(int x)
{
    //aim : we need to turn off the right most set bit 
    // examples 
    // 100 -> 000
    // 101 -> 100
    // 11010 -> 11000

    /*
    approach : 
    -> we will assign a variable 1
    -> perform & operation with the number 
    -> if it gives 1 : then return number ^ var
    -> otherwise leftshift var with 1
    */
    int temp = 1;
    while(!(x & temp))
    {
        temp = temp<<1;
    }
    return x^temp;

    //another approach : perform & operation with the number -1
    //return x & (x-1);
}
int main()
{
    int num= 12;
    cout<<TurnOffRightBit(num)<<endl;
    return 0;
}