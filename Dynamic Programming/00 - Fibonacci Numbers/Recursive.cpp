#include<iostream>
using namespace std;

//recursive approach
//time complexity: O(n)
//space compleity: O(n)
int Fibonacci(int n)
{
    if(n<=1)
        return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
    int n = 5;
    cout<<Fibonacci(n)<<endl;
}