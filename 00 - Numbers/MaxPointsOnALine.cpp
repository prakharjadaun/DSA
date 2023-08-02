#include<vector>
#include<unordered_map>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        if(n<=2)
            return n;
        int ans = 0;
        unordered_map<double,int> hashmap;
        for(auto it1: points)
        {
            hashmap.clear();
            double x1 = it1[0], y1 = it1[1];
            for(auto it2: points)
            {
                if(it1 == it2)
                    continue;
                
                double x2 = it2[0], y2 = it2[1];
                double slope;
                if(x2-x1==0)    
                    slope = INT_MAX;
                else
                    slope = (y2-y1)/(x2-x1);

                hashmap[slope]++;
                ans = max(ans,hashmap[slope]);
            }
        }
        return ans+1;
    }
};