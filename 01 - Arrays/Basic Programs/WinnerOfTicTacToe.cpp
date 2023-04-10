#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool check(vector<vector<int>> matrix,int n)
    {
        if(matrix[0][0]==n && matrix[0][1]==n && matrix[0][2]==n)
            return true;
        else if(matrix[1][0]==n && matrix[1][1]==n && matrix[1][2]==n)
            return true;
        else if(matrix[2][0]==n && matrix[2][1]==n && matrix[2][2]==n)
            return true;
        else if(matrix[0][0]==n && matrix[1][0]==n && matrix[2][0]==n)
            return true;
        else if(matrix[0][1]==n && matrix[1][1]==n && matrix[2][1]==n)
            return true;
        else if(matrix[0][2]==n && matrix[1][2]==n && matrix[2][2]==n)
            return true;
        else if(matrix[0][0]==n && matrix[1][1]==n && matrix[2][2]==n)
            return true;
        else if(matrix[0][2]==n && matrix[1][1]==n && matrix[2][0]==n)
            return true;

        return false;
    }
    string tictactoe(vector<vector<int>>& moves) 
    {
        vector<vector<int>> matrix;
        matrix.push_back({0,0,0});
        matrix.push_back({0,0,0});
        matrix.push_back({0,0,0});

        for(int i=0;i<moves.size();i++)
        {
            if(i%2==0)
                matrix[moves[i][0]][moves[i][1]] = 1;
            else
                matrix[moves[i][0]][moves[i][1]] = -1;
        }    

        if(check(matrix,1))
            return "A";
        else if(check(matrix,-1))
            return "B";
        else if(moves.size()==9)
            return "Draw";
        
        return "Pending";
    }
};