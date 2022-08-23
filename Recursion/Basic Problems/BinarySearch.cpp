#include<iostream>                  //for input and output stream
#include<stdlib.h>                  //for malloc function
using namespace std;

//space complexity : O(1)
//time complexity : O(log n)


//boolean variable as to know if the element was found or not
bool flag = false;
//definition of the binary search function 
void BinarySearch(int arr[],int beg,int end, int res)
{
    if(beg<end)
    {
        //finding the middle index of the sub array or array passed
        int mid = (beg+end)/2;
        if(arr[mid]==res)                   //if element found
        {
            cout<<"element found...!"<<endl;
            flag = true;
            return;
        }
        else if(res < arr[mid])             //if the element we have to find is smaller than the middle element of the array or the subarray        
        {
            end = mid-1;                    //changing the end index of the array as mid-1
            BinarySearch(arr,beg,end,res);
        }
        else                                //if the element we have to find is greater than the middle element of the array or the subarray
        {
            beg = mid+1;                    //changing the beginning index of the array as mid+!
            BinarySearch(arr,beg,end,res);
        }
    }
}


int main()
{
    //declaring the variable
    int n;
    //getting n as input
    cout<<"Enter n : ";
    cin>>n;
    //declaring a pointer to an integer array using dyanmic memory allocation
    //here we have used the malloc function
    int *arr = (int*)malloc(n*sizeof(int));
    //getting the input of the array
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i+1<<" : ";
        cin>>arr[i];
    }

    int temp;
    //getting the input a number that we have to search
    cout<<"Enter the number you want to search : ";
    cin>>temp;
    //calling the binary search function
    BinarySearch(arr,0,n-1,temp);
    if(!flag)                       //if the element not found
    {
        cout<<"element not found...!"<<endl;
    }
    return 0;
}