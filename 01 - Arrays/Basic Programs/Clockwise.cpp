#include<iostream>
using namespace std;

//function to rotate the array in clockwise direction by 1
void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

//function to print the array
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //1 2 3 4 5 
    //output : 5 1 2 3 4

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array :";
    printArray(arr,n);

    rotate(arr,n);

    cout<<"Rotated Array : ";
    printArray(arr,n);

}