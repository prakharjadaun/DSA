#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        int flagrow[9][9] = {0},flagcol[9][9] = {0}, flagbox[9][9] = {0};
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                    continue;
                int num = board[i][j]-'0'-1;
                int k = (i / 3) * 3 + j/3;
                if(flagrow[i][num] || flagcol[j][num] || flagbox[k][num])
                    return false;
                flagrow[i][num] = flagcol[j][num] = flagbox[k][num] = 1;
            }
        }
        return true;
    }
};