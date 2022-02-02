#include <bits/stdc++.h>

using namespace std;

class myStack{
    public:
        int actualVal;
        int minVal;
};

class MinStack {
    
public:
    stack<myStack> st;
    MinStack() {
    }
    void push(int val) {
        myStack item;
        item.actualVal = val;
        if(st.empty())
        {
            item.minVal = val;
        }
        else
        {
            if(val<st.top().minVal)
            {
                item.minVal = val;
            }
            else
            {
                item.minVal = st.top().minVal;
            }
        }
        st.push(item);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return(st.top().actualVal);
    }
    
    int getMin() {
        return(st.top().minVal);
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