#include<vector>
using namespace std;
class CustomStack {
public:
    vector<int> st;
    int len;
    CustomStack(int maxSize) 
    {
        len = maxSize;
    }
    void push(int x) 
    {
        if(st.size()<len)
        st.push_back(x);
    }
    
    int pop() 
    {
        if(st.size()==0)
        return -1;
        int temp = st[st.size()-1];
        st.erase(st.end()-1);
        return temp;    
    }
    
    void increment(int k, int val) 
    {
        for(int i=0;i<k;i++)
        {
            if(i<st.size())
            {
                st[i] = st[i] + val;
            }
        }    
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */