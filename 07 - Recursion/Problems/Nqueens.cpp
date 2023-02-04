#include<vector>
using namespace std;
#include<stdlib.h>
#include<string>
class Solution {
    vector<vector<string>> ans;
    //function to assign -1 to all the indices of the pos 
    void assign(int *pos,int n)
    {
        for(int i=0;i<n;i++)
        {
            pos[i]=-1;
        }
    }
    //function solve to allocate memory to pos array and call the put_queen function
    void solve(int n)
    {
        int *pos = (int *)malloc(n*sizeof(int));
        assign(pos,n);

        put_queen(pos,0,n);
    }
    //function to put queen 
    void put_queen(int *pos,int target_row,int n)
    {
        if(target_row==n)
        {
            append(pos,n);
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(check_place(pos,target_row,i))
                {
                    pos[target_row] = i;
                    put_queen(pos,target_row+1,n);
                }
            }
        }
    }

    //function to check whether the queen is in the same row, diagonal or the another diagonal
    bool check_place(int *pos,int occupied_row, int column)
    {
        for(int i=0;i<occupied_row;i++)
        {
            if(pos[i]==column || pos[i]-i == column-occupied_row || pos[i]+i == column + occupied_row)
            return false;
        }
        return true;
    }
    //function to append the solution to the answer vector
    void append(int *pos,int n)
    {
        string s;
        vector<string> temp;
        for(int i=0;i<n;i++)
        {
            s="";
            for(int j=0;j<n;j++)
            {
                if(pos[i]==j)
                {
                    s+="Q";
                }
                else
                {
                    s+=".";
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
        temp.clear();
    }

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        solve(n);
        return ans;
    }
};