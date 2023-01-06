#include<iostream>
using namespace std;
class Solution{
    public:
    int findSingle(int N, int arr[]){
        // code here
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            ans = ans ^ arr[i];
        }
        return ans;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    Solution sol;
    cout<<sol.findSingle(n,arr)<<endl;
}