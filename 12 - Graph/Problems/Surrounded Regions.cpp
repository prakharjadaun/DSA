#include<vector>
using namespace std;
class Solution {
public:
    //function to perform DFS 
    void DFS(int i, int j, vector<vector<char>> &ans, vector<vector<char>> board)
    {
        int m = board.size();
        int n = board[0].size();
        //if the 
        //- indices are not valid return
        //if the ans[i][j]!='-' return because it might have visited already
        //if board[i][j] contains X then we cannot flip it to O, return
        if(i<0 || j<0 || i==m || j==n || ans[i][j]!='-' || board[i][j]=='X')
            return;

        ans[i][j] = 'O';

        DFS(i-1,j,ans,board);
        DFS(i+1,j,ans,board);
        DFS(i,j-1,ans,board);
        DFS(i,j+1,ans,board);
    }
    void solve(vector<vector<char>>& board) 
    {
        //get the shape of the board
        int m = board.size();
        int n = board[0].size();
        //create a vector to store the i,j which contains zeros on boundary
        vector<pair<int,int>> boundaryzeros;
        //answer vector initially filled with '-'
        vector<vector<char>> ans(m,vector<char>(n,'-'));

        //storing the boundary zeros indices
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O')
                    boundaryzeros.push_back({i,j});
            }
        }

        //traversing DFS on the boundary O's and flipping all the '-' to 'O' that are connected
        for(auto temp : boundaryzeros)
        {
            DFS(temp.first,temp.second,ans,board);   
        }

        //lastly flipping all '-' with 'X'
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]=='-')
                    ans[i][j]='X';
            }
        }

        //assiging board as ans
        board = ans;
    }
};