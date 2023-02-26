#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string,int> h1,h2;
        for(int i=0;i<list1.size();i++)
        {
            if(h1.find(list1[i])==h1.end())
            {
                h1[list1[i]] = i;
            }
        }  

        for(int i=0;i<list2.size();i++)
        {
            if(h2.find(list2[i])==h2.end())
            {
                h2[list2[i]] = i;
            }
        }    

        int min_ind_sum = INT_MAX;

        for(auto temp : h1)
        {
            if(h2.find(temp.first)!=h2.end())
            {
                if(min_ind_sum > temp.second + h2[temp.first])
                {
                    min_ind_sum = temp.second + h2[temp.first];
                }
            }
        }
        vector<string> ans;

        for(auto temp : h1)
        {
            if(h2.find(temp.first)!=h2.end() && h2[temp.first]+temp.second == min_ind_sum)
            {
                ans.push_back(temp.first);
            }
        }
        return ans;
    }
};