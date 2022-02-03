#include <bits/stdc++.h>
using namespace std;

#define max(a,b) (a>b?a:b);
class MyQueue {
public:
    stack <int>one;
    stack <int>two;
    MyQueue() {

    }
    
    void push(int x) {
        // remove one elements to stack two
        while(one.empty()!= true)
        {
            two.push(one.top());
            one.pop();
        }
        one.push(x);
        // push back elements from two
        while(two.empty() !=true)
        {
            one.push(two.top());
            two.pop();
        }
    }
    
    int pop() {
        int val;
        val = one.top();
        one.pop();
        return val;
    }
    
    int peek() {
        return one.top();
    }
    
    bool empty() {
        return(one.empty());
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