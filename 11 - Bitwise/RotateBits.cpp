#include<bits/stdc++.h>
using namespace std;
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            vector<int> ans;
            int x,y;
            d = d%16;
            x = (n<<d | (n>>(16-d))) & 0xFFFF;
            y = (n>>d | (n<<(16-d))) & 0xFFFF;
            ans.push_back(x);
            ans.push_back(y);
            return ans;
        }
};