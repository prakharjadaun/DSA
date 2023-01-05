#include<iostream>
using namespace std;
int main()
{
          //11   //10
    int a = 3, b = 2;
    
    //1. bitwise & 
    // performs and operation on all the bits of the two operands
    //     10
    cout<< (a & b)<<endl;


    //2. bitwise ||
    //performs OR operation on all the bits of two operands
    //      11
    cout<< (a|b)<<endl;

    //3. bitwise XOR 
    //performs XOR operations on all the bits of two operands
    //results in 1 if both the bits are different
    //      01
    cout<<(a ^ b)<<endl;

    //4. left shift 
    //      110
    cout<< (a << 1) <<endl;

    //5. Right Shift
    //      1
    cout<< (a >> 1)<<endl;

    //bitwise NOT 
    // ~ 
    // ~a = -(a + 1)
    cout<< (~ a)<<endl;
}