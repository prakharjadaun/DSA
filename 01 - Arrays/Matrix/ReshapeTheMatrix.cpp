#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        //storing the size of matrix in m and n 
        int m = mat.size(), n = mat[0].size();
        //checking if the passed r and c are equal to m and n
        //if true, return the matrix
        if(m == r && n == c)
            return mat;
        //again checking if the matrix reshaping is possible or not,
        //if not possible then return the original matrix
        if(m*n != r*c)
            return mat;
        //create matrix 
        //way to allocate memory for a matrix
        vector<vector<int>> ans(r,vector<int>(c));
        
        //iterate through r*c times 
        for(int i=0;i<r*c;i++)
            //accessing the row and col
            ans[i/c][i%c] = mat[i/n][i%n];
        return ans;
    }
};