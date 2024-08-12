class KthLargest {
public:
    int cap = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        //priority_queue<int> pq;
        cap = k;
        for(auto el:nums){
            if(pq.empty() || pq.size()<cap){
                pq.push(el);
            }
            else if(pq.size()==cap && el>pq.top()){
                pq.pop();
                pq.push(el);
            }
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()<cap){
            pq.push(val);
        }
        else if(pq.size()==cap && val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */