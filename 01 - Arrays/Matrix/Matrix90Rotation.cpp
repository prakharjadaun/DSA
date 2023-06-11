#include<vector>
using namespace std;
class Solution {
public:

    //function to transpose the matrix
    vector<vector<int>> transpose(vector<vector<int>> matrix)
    {
        for(int i=0;i<matrix.size()-1;i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        return matrix;
    }
    //function to get the reflection of the matrix
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
    //function to rotate the matrix by 90 degree
    void rotate(vector<vector<int>>& matrix) 
    {
        //there are two steps to rotate the matrix by 90 degree
        //first found the tranpose of the matrix
        matrix = transpose(matrix);
        //second is to found the reflection of the image
        matrix = reflect(matrix);
    }
};