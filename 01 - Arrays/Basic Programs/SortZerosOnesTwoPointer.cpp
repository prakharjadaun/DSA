#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size()-1;

    for(int i=0;i<arr.size();i++)
    {
        switch(arr[mid])
        {
            case 0:     swap(arr[low++],arr[mid++]);
                        break;
            case 1:     mid++;
                        break;
            case 2:     swap(arr[mid],arr[high--]);
        }
    }
    
}

void display(vector<int> arr)
{
    cout<<endl<<"Array: ";
    for(int i: arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {0,1,2,0,1,2};
    display(arr);
    solve(arr);
    display(arr);
}
