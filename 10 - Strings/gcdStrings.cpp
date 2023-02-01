#include<string>
#include<numeric>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        if(str1+str2 == str2+str1)
            return str1.substr(0,__gcd(str1.size(),str2.size()));
        return "";
    }
};