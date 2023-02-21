#include<unordered_map>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        map<int,int> hashmap;
        vector<int> ans;
        vector<int> last;
        for(int i=0;i<arr1.size();i++)
        {
            hashmap[arr1[i]]++;
        }    

        for(int i=0;i<arr2.size();i++)
        {
            int temp = hashmap[arr2[i]];
            for(int j=0;j<temp;j++)
            {
                ans.push_back(arr2[i]);
            }
            hashmap.erase(arr2[i]);
        }

    
        for(auto temp : hashmap)
        {
            int n = temp.second;
            for(int i=0;i<n;i++)
            {
                last.push_back(temp.first);
            }
        }

       
        ans.insert(ans.end(),last.begin(),last.end());
        return ans;
    }

};