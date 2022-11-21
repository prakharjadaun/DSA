#include<bits/stdc++.h>
using namespace std;

//recursive function to find out the factorial of a number 
int Fact(int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    else
        return n*Fact(n-1);
}

int main()
{
    //declaring a integer variable
    int n;
    //getting the input
    cout<<"Enter a number : ";
    cin>>n;
    //printing the factorial of the number 
    cout<<Fact(n)<<endl;
    return 0;
}