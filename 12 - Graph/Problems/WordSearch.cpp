#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool DFS(vector<vector<char>> &board,string word, int i, int j, int n)
    {
        //if we have reached the out of index, we have got the string
        //return true
        if(n==word.size())
            return true;
        
        //check the base cases
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[n])
            return false;
        
        //mark the current char visited
        board[i][j] = '0';

        //compute the DFS in 4-directions
        bool flag = DFS(board, word, i + 1, j, n + 1) ||  //down
                        DFS(board, word, i, j + 1, n + 1) ||  //right
                        DFS(board, word, i - 1, j, n + 1) ||  //up
                        DFS(board, word, i, j - 1, n + 1);  //left
        //after reassign its  original value
        board[i][j] = word[n];
        //return the flag
        return flag;

    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        if(word=="")
            return false;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
                if(board[i][j]==word[0] && DFS(board,word,i,j,0))
                    return true;
        }    
        return false;
    }
};