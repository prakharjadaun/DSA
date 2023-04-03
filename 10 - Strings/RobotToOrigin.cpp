#include<iostream>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int x = 0, y = 0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[i]=='L')
            {
                x = x - 1;
            }
            else if(moves[i]=='R')
            {
                x = x + 1;
            }
            else if(moves[i]=='U')
            {
                y = y + 1;
            }
            else
            {
                y = y - 1;
            }
        }    
        return (x == 0 && y ==0);
    }
};