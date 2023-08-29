class MyStack {
public:
    void rev(queue<int>& q){
        int cap = q.size();
        int i = 0;
        while(i<cap-1){
            q.push(q.front());
            q.pop();
            i++;
        }
        return;
    }
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        rev(q);
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */