#include<string>
using namespace std;
class Solution {
public:
    string interpret(string command) 
    {
        string ans = "";
        for(int i=0;i<command.size();i++)
        {
            if(command[i] == 'G')
            {
                ans += "G";
            }
            else if(i+1 != command.size() && command[i] == '(' && command[i+1]==')')
            {
                ans += "o";
            }
            else if(i+3 < command.size() && command[i]=='(' && command[i+1]=='a')
            {
                ans+= "al";
            }
        }    
        return ans;
    }
};