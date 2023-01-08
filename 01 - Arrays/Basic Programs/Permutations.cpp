#include<iostream>
#include<algorithm>
using namespace std;

void printPermutations(int arr[], int n)
{
    do 
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(arr,arr+n));
}

int main()
{
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printPermutations(arr,n);
    return 0;
}