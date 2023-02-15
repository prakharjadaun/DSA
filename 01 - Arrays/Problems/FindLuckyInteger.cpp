#include<vector>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        vector<int> fre(501,0);

        for(int n : arr)
        {
            fre[n]++;
        }
        bool flag = false;
        for(int i=500;i>0;i--)
        {
            if(fre[i] == i)
            {
                return i;   
            }
        }
        return -1;
    }
};