#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) 
    {
        //passing a comparator function in the sort function
        //if both the numbers are having equal number of 1 bits then passing the bool whether a is small or not
        //if both the numbers are having unequal number of 1 bits then passing the bool whether a has small number of 1 bits or not
        sort(arr.begin(),arr.end(),[](int &a,int &b){if(__builtin_popcount(a)== __builtin_popcount(b)) return a<=b; else return __builtin_popcount(a)< __builtin_popcount(b); });
        return arr;    
    }
};