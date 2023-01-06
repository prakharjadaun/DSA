#include<bits/stdc++.h>
using namespace std;
int multiplyBy7(int num)
{
    if(num==0)
        return 0;
    
    //lets say num = 4 -> 100
    //after mutli.= 28 -> 11100

    //lets say num = 3 -> 11
    //after multi.= 21 -> 10101

    //to achieve this first we left shift 3 bits the original number and subtract the original number from it
    return (num<<3)-num; 
}
int main()
{
    // 100
    int num = 4;
    cout<<multiplyBy7(num)<<endl;
}