#include<iostream>
using namespace std;
int multiply(int x)
{
    //approach : add the left shift and right shift of number by 1 to the original number 
    //example : 4 -> 100 
    // left shift by 1 -> 1000
    // right shift by 1 -> 010
    // adding them up 
    // 100
    //1000
    // 010 
    // ----
    // 1110 -> 14 (4 x 3.5)
    return (x<<1 + x + x>>1);
}
int main()
{
    //multiplication by 3.5 without any division and multiplication operator
    int num = 4;
    cout<<multiply(num)<<endl;
}