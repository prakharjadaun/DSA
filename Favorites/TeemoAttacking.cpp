#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:

    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int res = 0;
        // adding an extra element to the timeSeries list, (10e7 because of the constraint)
        timeSeries.push_back(10000000);
        // basic formula = sum(min(duration,next_attack_time - current_attack_time))
        for(int i=0;i<timeSeries.size()-1;i++)
        {
            //storing the sum in the res variable
            res += min(duration,timeSeries[i+1]-timeSeries[i]);
        }
        return res;
    }
};

// python solution: 
/*
def findPoisonedDuration(self, s, d):
        return sum(min(d, b - a) for a, b in zip(s, s[1:] + [10e7]))
*/