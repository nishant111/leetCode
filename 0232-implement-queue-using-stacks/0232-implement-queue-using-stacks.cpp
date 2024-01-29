class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    bool remove = true;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            int curr = st1.top();
            st1.pop();
            st2.push(curr);
        }
        int ret = st2.top();
        if(remove)
            st2.pop();
        while(!st2.empty()){
            int curr = st2.top();
            st2.pop();
            st1.push(curr);
        }
        return ret;
    }
    
    int peek() {
        remove = false;
        int ret = pop();
        remove = true;
        return ret;
    }
    
    bool empty() {
        return (st1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */