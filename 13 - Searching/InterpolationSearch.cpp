#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//time complexity: O(log2(log2 n)) for the average case, and O(n) for the worst case 
//Auxiliary Space Complexity: O(1)
bool interpolationSearch(vector<int> arr, int val)
{
    int low = 0, high = arr.size() - 1;
    int i=0;
    while(low<high)
    {
        cout<<"Iter:"<<i<<endl;
        int mid = low + (((high - low) /(arr[high] - arr[low])) * (val - arr[low]));
        cout<<"Mid: "<<mid<<endl;
        if(arr[mid] == val)
            return true;
        else if(arr[mid] > val)
            high = mid - 1;
        else
            low = mid + 1;
        i++;
    }
    return false;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    sort(arr.begin(),arr.end());
    int val = 1;
    cout<<interpolationSearch(arr,val)<<endl;
}