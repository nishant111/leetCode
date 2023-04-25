class SmallestInfiniteSet {
public:
    int insertionRange=10;
    priority_queue<int, vector<int> , greater<int>>container;
    unordered_set<int> st;
    int smallest =1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int ret;
        if(container.size()==0) {
            ret = smallest;
            smallest++;
        }
        else{
            ret = container.top();
            container.pop();
            st.erase(ret);
        }
        return ret;
    }
    void addBack(int num) {
        if(smallest<=num || st.find(num)!=st.end()) return;
        st.insert(num);
        // insertions will be at the ends for all cases
        container.push(num);
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */