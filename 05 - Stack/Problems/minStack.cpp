#include<stack>
#include<vector>
#include<climits>
using namespace std;
class MinStack {
public:
    int min_num;
    stack<int> st;
    vector<int> temp;
    MinStack() 
    {
        min_num = INT_MAX;
        temp.push_back(min_num);
    }
    
    void push(int val) 
    {
        st.push(val); 
        if(val <= min_num)
        {
            min_num = val;
            temp.push_back(min_num);
        }
    }
    
    void pop() 
    {
        int t = st.top();
        st.pop();
        if(t == min_num)
        {
            temp.pop_back();
            min_num = temp[temp.size()-1];
        }
    }
    
    int top() 
    {
        return st.top();    
    }
    
    int getMin() 
    {
        return min_num;    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */