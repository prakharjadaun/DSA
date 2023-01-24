#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        unordered_map<string,int> s;
        for(int i=0;i<arr.size();i++)
        {
            s[arr[i]]++;
        }
        string ans = "";
        int m = 0;
        for(int i=0;i<arr.size();i++)
        {
            if(s[arr[i]]==1)
            m++;
            if(m==k)
            {
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
};