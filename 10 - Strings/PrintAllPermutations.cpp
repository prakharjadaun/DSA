#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void permute(string &a, int l, int r)
{
    if(l==r)
        cout<<a<<endl;
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(a[l],a[i]);

            permute(a,l+1,r);

            swap(a[l],a[i]);
        }
    }
}

int main()
{
    string A = "ABC";
    permute(A,0,A.size()-1);
    // do
    // {
    //     cout<<A<<endl;
    // }while(next_permutation(A.begin(),A.end()));
}