#include<iostream>
#include<string>
using namespace std;
class Solution 
{
public:
    string removeStars(string s) 
    {
        string res ;
        for(char ch : s)
        {
            if(ch == '*')
                res.pop_back();
            else
                res += ch;
        }
        return res;
    }
};



int main()
{
    string str;
    Solution sol;
    cin>>str;
    cout<<sol.removeStars(str)<<endl;
    return 0;
}