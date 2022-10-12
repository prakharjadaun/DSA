#include<iostream>
using namespace std;

void sortArray(int arr[],int n)
{
    int ones=0,twos=0,zeros=0;

    //getting the count of One's, Two's and Zero's
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
            zeros++;
        else if(arr[i]==1)
            ones++;
        else
            twos++;
    }

    for(int i=0;i<n;i++)
    {
        if(i<zeros) 
        {
            arr[i] = 0;
        }
        else if(i<zeros+ones)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 2;
        }
    }
}

int main()
{
    //initializing the array
    int arr[] = {0,1,2,2,0,1,1,2};
    //getting the size of array
    int n = sizeof(arr)/sizeof(arr[0]);
    //printing the original array 
    cout<<"Original Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sortArray(arr,n);
    //printing the sorted array 
    cout<<"Printing the sorted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}