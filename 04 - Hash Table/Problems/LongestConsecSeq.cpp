#include<set>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> hashset(nums.begin(),nums.end());
        int maxSeq = 0, temp = 1;
        for(int i: hashset)
            cout<<i<<" ";
        cout<<endl;
        set<int>::iterator it = hashset.begin();

        while(it!=hashset.end())
        {   
            if(*it+1 == *(++it)){
                cout<<*it<<endl;
                temp++;
            }
            else
            {
                if(maxSeq<temp)
                    maxSeq = temp;
                temp = 1;
            }
        }
        if(maxSeq<temp)
            maxSeq = --temp;
        return maxSeq;
    }
};