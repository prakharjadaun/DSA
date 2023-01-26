#include<vector>
using namespace std;
class Solution {
public:
    //this can easily be achieved by first tranposing the matrix and the reflecting the matrix
    vector<vector<int>> transpose(vector<vector<int>> matrix)
    {
        for(int i=0;i<matrix.size()-1;i++)
        {
            for(int j=i+1;j<matrix.size();j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return matrix;
    }

    vector<vector<int>> reflect(vector<vector<int>> matrix)
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size()/2;j++)
            {
                swap(matrix[i][j],matrix[i][matrix.size()-1-j]);
            }
        }
        return matrix;
    }
    void rotate(vector<vector<int>>& matrix) 
    {
        matrix = transpose(matrix);
        matrix = reflect(matrix);
    }
};