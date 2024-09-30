class CustomStack {
public:
    int cap;
    vector<int> st;
    int size;
    int iter;
    CustomStack(int maxSize) {
        cap = maxSize;
        st = vector<int> (cap);
        size = 0;
        iter = 0;
    }
    
    void push(int x) {
        if(size == cap)
            return;
        st[iter++]=x;;
        size++;
    }
    
    int pop() {
        if(size == 0)
            return -1;
        int ret = st[iter-1];
        st.pop_back();
        size--;
        iter--;
        return ret;
    }
    
    void increment(int k, int val) {
        int lim = min( k, iter);
        for(int i = 0;i<lim;i++){
            st[i] += val;
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