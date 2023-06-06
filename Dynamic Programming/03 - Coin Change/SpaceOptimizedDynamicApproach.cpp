#include<iostream>
#include<cstring>
using namespace std;

//time complexity: O(n*sum)
//space complexity: O(sum)
int count(int coins[], int n, int sum)
{
    //creating a target array with size equal to sum
    int target[sum+1];

    //filling the whole target array with 0
    memset(target,0,sizeof(target));

    //base case
    target[0] = 1;

    //calculating the answer
    for(int i=0;i<n;i++)
    {
        for(int j=coins[i];j<=sum;j++)
            target[j] += target[j - coins[i]];
    }
    //returning the coin change
    return target[sum];
}

int main()
{
    int coins[] = {1,2,3};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 4;

    cout<<count(coins,n,sum)<<endl;

}