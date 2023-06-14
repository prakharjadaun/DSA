#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        unordered_set<int> row, col;
        //O(m*n)
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                //if element in matrix with value is zero encountered, then store that row and col value in the row and col unordered set
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }   
        }

        //then iterating on those row and columns to set those rows and col zeros
        for(int temp: row)
        {
            for(int j=0;j<matrix[temp].size();j++)
                matrix[temp][j]=0;
        }

        for(int temp: col)
        {
            for(int j=0;j<matrix.size();j++)
                matrix[j][temp]=0;
        }

    }
};