#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Ordered Linear Search: In ordered linear search we do not need to traverse the whole array if the element is not present. 
// we can apply the condition that if the current traversed element is greater than the value to be searched, then the element do not exist
bool findEle(vector<int> arr,int val)
{
    //function to sort the array
    sort(arr.begin(),arr.end());
    for(int i: arr)
    {
        if(i == val)
            return true;
        //additional condition
        else if(i > val)
            return false;
    }
    return false;
}
//Time complexity of this algorithm is O(n).This is because in the worst case we need to scan thecomplete array. But in the average case it reduces the complexity even though the growth rate is the same.
//Space complexity: O(1).

int main()
{
    vector<int> arr = {1,2,3,4};
    int val = 4;

    cout<<findEle(arr,val)<<endl;
}