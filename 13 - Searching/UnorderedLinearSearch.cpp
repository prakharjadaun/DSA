#include<iostream>
#include<vector>
using namespace std;

//time complexity: O(n)
//space complexity: O(1)
bool findEle(vector<int> arr, int val)
{
    for(int ele: arr)
        if(ele == val)
            return true;
            
    return false;
}

int main()
{
    vector<int> arr = {1,2,3,4};
    int val = 4;
    cout<<findEle(arr,val)<<endl;
}