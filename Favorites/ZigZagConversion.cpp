#include<vector>
#include<string>
using namespace std;
#include<math.h>
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1)
            return s;
        

        //calculating the columns of the matrix representation
        int n = int(s.size());
        int parts = ceil(n/(2*numRows - 2.0));
        int numCols = parts * (numRows - 1);

        //defining the matrix with the rows and columns
        vector<vector<char>> matrix(numRows, vector<char>(numCols,' '));

        int currRow = 0, currCol = 0;
        int currStringIndex=0;

        while(currStringIndex < n)
        {
            //traversing down the matrix and storing the string elements
            while(currRow < numRows && currStringIndex<n)
            {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow++;
                currStringIndex++;
            }

            currRow = currRow - 2;
            currCol += 1;
            //moving up diagonally and storing the matrix elements
            while(currRow > 0 && currCol < numCols && currStringIndex < n)
            {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }

        string ans;
        //traversing each row and its elements and adding the characters to the string answer except the whitespaces
        for(auto &row: matrix)
        {
            for(auto& ch : row)
            {
                if(ch!=' ')
                    ans+= ch;
            }
        }
        return ans;
    }
};