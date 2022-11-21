#include<stack>
#include<iostream>
#include<string>
using namespace std;
class ValidParenthesis {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(' || i=='[' || i=='{')
            st.push(i);
            else
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']'))
                return false;
                st.pop();
            }
            
        }
        return st.empty();
    }
};


int main()
{
    ValidParenthesis s;
    string temp = "()";
    cout<<s.isValid(temp)<<endl;
}