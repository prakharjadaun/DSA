#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        //pascal's triangle always have 1 as its top 
        ans.push_back({1});
        //if the size is 1 then return ans
        if(numRows == 1)
            return ans;
        //inserting 1,1 as its second layer
        ans.push_back({1,1});
        if(numRows == 2)
            return ans;
        
        int n = numRows - 2;
        int prev = 1;
        int xyz;
        //decrementing until n becomes 0 
        while(n!=0)
        {
            //getting the pairwise sum from the previous layer and adding the next layer
            for(int i=0;i<ans[prev].size()-1;i++)
            {
                xyz = ans[prev][i] + ans[prev][i+1];
                temp.push_back(xyz);
            }
            //inserting 1 to the front and back of the new layer
            temp.insert(temp.begin(),1);
            temp.push_back(1);
            //inserting the new layer to our answer vector
            ans.push_back(temp);
            //clearing the vector containing the new layer so that new layer can be inserted into it
            temp.clear();
            prev++;
            n--;
        }
        return ans;
    }
};