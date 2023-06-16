#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.size()==0)
            return {};

        vector<int> ans;
        int rowBegin = 0;
        int rowEnd = matrix.size()-1;
        int colBegin = 0;
        int colEnd = matrix[0].size()-1;

        while(rowBegin<=rowEnd && colBegin <= colEnd)
        {
            //traversing right
            for(int j=colBegin;j<=colEnd;j++)
                ans.push_back(matrix[rowBegin][j]);

            //row traversed
            rowBegin++;

            //traversing down
            for(int k=rowBegin;k<=rowEnd;k++)
                ans.push_back(matrix[k][colEnd]);

            //col traversed
            colEnd--;

            if(rowBegin<=rowEnd)
            {
                //traversing left
                for(int j=colEnd;j>=colBegin;j--)
                    ans.push_back(matrix[rowEnd][j]);
            }
            //row traversed
            rowEnd--;

            if(colBegin<=colEnd)
            {
                //traversing up
                for(int j=rowEnd;j>=rowBegin;j--)
                    ans.push_back(matrix[j][colBegin]);
            }
            //col traversed
            colBegin++;
        }
        return ans;
    }
};