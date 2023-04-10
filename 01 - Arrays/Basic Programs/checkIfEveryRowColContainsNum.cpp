#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        unordered_set<int> hashset_row,hashset_col;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                hashset_row.insert(matrix[i][j]);
                hashset_col.insert(matrix[j][i]);
            }
            if(hashset_row.size()!=matrix.size())
                return false;
            if(hashset_col.size()!=matrix.size())
                return false;
            hashset_row.clear();
            hashset_col.clear();
        }  
        return true;
    }
};