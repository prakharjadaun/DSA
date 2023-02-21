#include<vector>
using namespace std;
class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) 
    {
        int arrsum = (n*(n+1))/2;
        
        int temp = 0;
        for(int i=0;i<n-1;i++)
        {
            temp += arr[i];
        }
        
        return arrsum - temp;
    }
};