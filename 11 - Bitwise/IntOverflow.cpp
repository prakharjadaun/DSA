#include<bits/stdc++.h>
using namespace std;
bool checkOverflow(int a,int b)
{
    //simple logic : 
    //overflow condition 
    // - if both the numbers are greater than 0 and their result is negative, overflow condition
    // - if both the numbers are smaller than 0 abnd their result is positive, overflow condition 
    //else not a overflow condition 
    int result = a+b;
    if(a > 0 && b>0 && result<0)
        return true;
    if(a < 0 && b< 0 && result > 0)
        return true;
    return false;
}
int main()
{
    int a = -2, b = INT_MIN;
    checkOverflow(a,b) ? cout << "True" : cout<<"False"<<endl;
}