#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    int maxIceCream(vector<int>& costs, int coins) 
    {
       sort(costs.begin(),costs.end());
       int  temp = 0,ans=0;
       for(int i=0;i<costs.size();i++)
       {
           temp += (costs[i]);
           if(temp <= coins)
           ans++;
           else
           break;
       }
       return ans;
    }
};