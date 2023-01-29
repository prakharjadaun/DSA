#include<unordered_set>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool check(string l,string r)
    {
        unordered_set<char> hashset1,hashset2;
        for(int i=0;i<l.size();i++)
        {
            hashset1.insert(l[i]);
        }
        for(int i=0;i<r.size();i++)
        {
            hashset2.insert(r[i]);
        }
        return hashset1.size()==hashset2.size();
    }
    
    int numSplits(string s) 
    {
        string sl,sr;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            sl = s.substr(0,i+1);
            sr = s.substr(i+1,s.size());

            if(check(sl,sr)==true)
            ans++;
        }
        return ans;
    }
};

int main()
{
    // string s = "aacaba";
    string s = "abcd";

    // cout<<s.substr(0,1+1)<<endl;
    // cout<<s.substr(1+1,s.size())<<endl;;
    Solution sol;
    cout<<sol.numSplits(s)<<endl;
}