#include <iostream>
using namespace std;

void Fib(int n)
{
    static int pre=0,nex=1,res;
    if (n>0)
    {
        res = pre + nex;
        pre = nex;
        nex = res;
        cout << res << endl;
        Fib(n-1);
    }
}

int main()
{
    // declaring a variable n
    int n;
    // getting the input n
    cout << "Enter a number upto which you want to print the fibonacci series : ";
    cin >> n;
    cout<<0<<endl<<1<<endl;
    Fib(n-2);
    return 0;
}