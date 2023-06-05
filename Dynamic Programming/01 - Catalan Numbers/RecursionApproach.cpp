#include<iostream>
using namespace std;

//time space complexity: O(2^n)
//space complexity: O(n)
unsigned long int catalan(int num)
{
    // Base case
    if (num <= 1)
        return 1;
        
    unsigned long int res = 0;

    for(int i=0;i<num;i++)
    {
        res += catalan(i) * catalan(num-i-1);
    }
    return res;
}

int main()
{
    //program to print the first 10 catalan numbers
    for(int i=0;i<10;i++)
    {
        cout<<catalan(i)<<endl;
    }
}