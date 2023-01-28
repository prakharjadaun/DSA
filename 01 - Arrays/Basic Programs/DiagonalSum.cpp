#include<vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int len = mat.size()-1;
        int ans=0;

        for(int i=0;i<=len;i++)
        {
            ans += mat[i][i];
            //checking if inverted diagonal is not equal to the right diagonal
            if(len-i != i)
            ans+= mat[i][len-i];
        }    
        return ans;
    }
};