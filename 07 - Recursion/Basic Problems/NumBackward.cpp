#include<bits/stdc++.h>
using namespace std;
void Print(int n)
{
    if(n!=0)
    {
        Print(n-1);
    }
    else
    {
        return;
    }
    cout<<n<<endl;
}
//main function
int main()
{
    //declaring a variable n 
    int n;
    //getting a input
    cout<<"Enter n : ";
    cin>>n;
    //printing n numbers from 1 to n
    Print(n);
}