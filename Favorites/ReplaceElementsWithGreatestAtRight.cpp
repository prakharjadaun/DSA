#include<vector>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int mx = -1;
        for(int i=arr.size()-1;i>=0;i--)
        {
            int temp = arr[i];
            arr[i] = mx;
            mx = max(temp,mx);
        }    
        
        return arr;
    }
};