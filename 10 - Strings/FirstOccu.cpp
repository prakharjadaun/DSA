#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        string temp ;
        //using the substring function to get substrings with size same as needles' 
        //then comparing each substring with needle whether they are equal to needle or not
        //if they are equal then, returning the index i at that current iteration
        //if we reaches the end of the loop, then there is no occurence of needle in haystack
        //thus returnining -1
        int len = haystack.size() - needle.size();
        for(int i=0;i<len+1;i++)
        {
            temp = haystack.substr(i,needle.size());
            if(temp == needle)
                return i;
            cout<<temp<<endl;
        }
        return -1;
    }
};

int main()
{
    string haystack = "hello", needle = "ll";
    Solution sol;
    cout<<sol.strStr(haystack,needle)<<endl;
}