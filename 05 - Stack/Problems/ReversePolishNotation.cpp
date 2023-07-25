#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<string> st;
        int res;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/")
            {
                st.push(tokens[i]);
            }
            else
            {
                int first = stoi(st.top());  st.pop();
                int second = stoi(st.top()); st.pop();

                int res;

                if(tokens[i]=="+")
                    res = first + second;
                if(tokens[i]=="-")
                    res = second - first;
                if(tokens[i]=="*")
                    res = first * second;
                if(tokens[i]=="/")
                    res = second / first;

                st.push(to_string(res));
            }
        }
        return stoi(st.top());
    }
};