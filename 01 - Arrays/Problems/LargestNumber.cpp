#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        //first convert all int elements to string
        vector<string> vec;
        for(auto temp : nums)
        {
            vec.push_back(to_string(temp));
        }    
        //sort the vec of string with passing a comparator function to the sort function 
        sort(vec.begin(),vec.end(), [](string &s1,string &s2){return s1+s2>s2+s1;});     
        //adding all the elements to the result variable   
        string ans="";
        for(auto temp: vec)
        ans += temp;
        //removing extra zeros if all the numbers are zeros
        while(ans[0]=='0' && ans.size()>1)
        ans.erase(0,1);

        return ans;
    }
};