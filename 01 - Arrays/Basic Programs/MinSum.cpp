#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumSum(int num) 
    {
        vector<int> temp;
        while(num!=0)
        {
            temp.push_back(num%10);
            num = num/10;
        }    
        sort(temp.begin(),temp.end());

        return ((temp[0]*10) + (temp[1]*10)+ temp[2] + temp[3]);
    }
};

