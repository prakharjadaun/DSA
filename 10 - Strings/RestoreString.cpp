#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        char *arr = new char[indices.size()+1];
        for(int i=0;i<indices.size();i++)
        {   
            arr[indices[i]] = s[i];
        }
        
        s = "";
        for(int i=0;i<indices.size();i++)
        {
            s += arr[i];
        }
        return s;
    }
};