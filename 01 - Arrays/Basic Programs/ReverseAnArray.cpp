#include<iostream>
using namespace std;

//function to reverse the array
void reverseArray(int arr[],int beg,int end)
{
    int temp;
    //iterating the half of the array
    // swapping the elements of beg and end index
    while(beg<end)
    {
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

//function to print the array
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //initializing an array
    int arr[] = {3,2,1,5,4};
    //getting the size of the array in n
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original array : ";
    printArray(arr,n);

    //calling the reverse array function 
    reverseArray(arr,0,n-1);

    //printing the reversed array
    cout<<"Reversed array : ";
    printArray(arr,n);

    return 0;
}