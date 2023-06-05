#include<iostream>
#include<vector>
using namespace std;

//function to reach n from 0
int minOperation(int n)
{
    vector<int> res(n+1,0);

    for(int i=1;i<=n;i++)
    {
        //add 1 to the previous element of the array
        res[i] = res[i-1] + 1;

        //if the index is even, find the min between current index and the i/2th element + 1
        if(i % 2 ==0)
        {
            res[i] = min(res[i],res[i/2] + 1);
        }
    }
    //returning the nth index element 
    return res[n];
}

int main()
{
    //passing the number to reach to the 
    cout<<minOperation(12)<<endl;
}