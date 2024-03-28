#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> hashmap;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                hashmap[i-j].push(mat[i][j]);
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j] = hashmap[i-j].top();
                hashmap[i-j].pop();
            }
        }
        return mat;
    }
};