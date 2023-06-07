#include<iostream>
#include<algorithm>
using namespace std;

//function to print all the permutations of the array
void printPermute(int arr[], int n)
{
    //time : O(n logn)
    sort(arr,arr+n);
    do
    {
        // time: O(n)
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;


    } // time : O(n!)
    while(next_permutation(arr,arr+n));
}

int main()
{
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printPermute(arr,n);
}
