class KthLargest {
public:
    priority_queue<int> pq;
    int cap;
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int i = 0;i<nums.size();i++)
        {
            int elem = nums[i];
            pq.push(-1 * elem);
            if(pq.size()>k)
            {
                pq.pop();
            }
            
        }
        
    }
    
    int add(int val) {
        pq.push(-1 * val);
        if(pq.size()>cap)
        {
            pq.pop();
        }
        
        return -1 * pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */