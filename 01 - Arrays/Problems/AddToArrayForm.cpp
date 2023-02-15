#include<vector>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
        int carry = 0;
        for(int i=num.size()-1;i>=0;i--)
        {
            int rem = k%10;
            num[i] = num[i] + carry + rem;
            if(num[i]%10 != num[i])
            {
                carry = 1;
                num[i] = num[i] % 10;
            }
            else
            {
                carry = 0;
            }
            k = k / 10;
        }

        while(k!=0)
        {
            int temp = k%10 + carry;
            if(temp % 10 != temp)
            {
                carry = 1;
                temp = temp % 10;
            }
            else
            {
                carry = 0;
            }
            num.insert(num.begin(),temp);
            k = k/10;
        }

        if(carry==1)
        {
            num.insert(num.begin(),1);
        }
        return num;
    }
};