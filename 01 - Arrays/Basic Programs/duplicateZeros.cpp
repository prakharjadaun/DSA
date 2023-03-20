#include<vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int len = arr.size();
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                arr.insert(arr.begin()+i,0);
                i++;
            }
        }    
        int curr = arr.size();
        for(int i=0;i<curr - len;i++)
        {
            arr.pop_back();
        }
    }
};