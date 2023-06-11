#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

//time complexity: O(n2)
/*
void maxFre(int arr[], int n)
{
    int freq = 0, ele = -1;
    for(int i=0;i<n;i++)
    {
        int temp = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[i] == arr[j] && i!=j)
                temp++;
        }
        if(temp > freq)
        {
            freq = temp;
            ele = arr[i];
        }
    }
}*/
//-------------------------------------------------------
//time complexity: O(n log n)
/*
void maxFre(int arr[], int n)
{
    //n log n
    sort(arr,arr+n);

    int freq = 0;
    int temp = 0;
    int ele = -1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
            temp++;
        else
        {
            if(temp > freq)
            {
                freq = temp;
                ele = arr[i-1];
            }
            temp = 0;
        }
    }
    cout<<"Max freq : "<<freq<<endl;
    cout<<"Element : "<<ele<<endl;
}*/
//-------------------------------------------------
//time: O(n)
//space : O(n)
/*
void maxFre(int arr[], int n)
{
    unordered_map<int,int> hashmap;
    for(int i=0;i<n;i++)
    {
        hashmap[arr[i]]++;
    }

    int freq = 0, ele = -1;
    for(auto temp : hashmap)
    {
        if(temp.second > freq)
        {
            freq = temp.second;
            ele = temp.first;
        }
    }
}
*/
//--------------------------------------------------------

//time complexity: O(n)
//space complexity: O(1)
//Moore's Algo
void maxFre(int arr[], int n)
{
    int count = 1;
    int res = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[res])
            count++;
        else
            count--;

        if(count == 0)
        {
            res = i;
            count = 1;
        }
    }

    //element with max frequency
    int ele = arr[res];

    int freq = 0;
    for(int i=0;i<n;i++)
        if(arr[i]==ele)
            freq++;
    
    cout<<"Max frequency: "<<freq<<endl;
    cout<<"Element: "<<ele<<endl;
}



int main()
{
    int arr[] = {1,2,3,2,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    maxFre(arr,n);
}