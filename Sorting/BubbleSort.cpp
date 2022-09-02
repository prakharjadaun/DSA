#include<iostream>
using namespace std;

//time complexity : O(n)
//function to sort the array using bubble sort
void BubbleSort(int arr[], int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//nain function 
int main()
{
    //declaring a array of integers
    int arr[] = {3,2,4,5,2,4,5};
    //getting the length of the array 
    int n = sizeof(arr)/sizeof(arr[0]);
    //calling the bubble sort function 
    BubbleSort(arr,n);
    //printing the sorted array
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}