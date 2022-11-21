#include<iostream>
#include<algorithm>
using namespace std;

// //using the inbuilt sorting algorithm
// void rearrange(int arr[], int n)
// {
//     sort(arr,arr+n);
// }

//function to shift all the negative numbers to the left of the array
void rearrange(int arr[],int n)
{
    int j=0;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            if(i!=j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
    }
}

int main()
{
    //initializing the array 
    int arr[] = {-1,-44,45,23,-67,45,-9};
    //getting the size of the array 
    int n = sizeof(arr)/sizeof(arr[0]);
    //printing the original array 
    cout<<"Original Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    rearrange(arr,n);

    //printing the sorted array 
    cout<<"Printing the shifted Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}