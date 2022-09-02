#include<iostream>
using namespace std;
//functino to sort the array using the insertion sort
void InsertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int j = i-1;
        //shifting the element and placing the key at the correct position in the sorted sub array 
        while(key < arr[j] && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
//main function
int main()
{
    //declaring a array of integers
    int arr[] = {2,3,1,4,5,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    //calling the insertion sort function 
    InsertionSort(arr,n);
    //printing the sorted array 
    cout<<"Sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}