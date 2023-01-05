#include<iostream>
using namespace std;
//function to detect whether the two integers are of opposite signs or not
bool detectOpposite(int a,int b)
{
    //approach 1 : simple if else comparison
    // if((a > 0 && b < 0) || (a < 0 && b> 0))
    // return true;
    // return false;

    //approach 2 : xor operation
    //if a number is negative then most significant bit is 1
    //if a number is positive then most significant bit is 0
    //so if perform xor operation on negative and positive number, then result will contain most significant bit as 1 that is the number will be negative
    return (a^b)<0;
}

int main()
{
    int a = 2, b = 3;
    cout<<detectOpposite(a,b)<<endl;
}
