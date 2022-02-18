#include <bits/stdc++.h>
using namespace std;
class KthLargest {
public:
    priority_queue<int> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        pq = {};
        size = k;
        for(int i = 0;i<nums.size();i++)
        {
            pq.push(-1 * nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(-1 * val);
        if(pq.size() > size) pq.pop();
        return (-1 * pq.top());
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */