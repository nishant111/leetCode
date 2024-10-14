class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for( auto el:nums){
            pq.push(el);
        }
        long long ans = 0;
        while(k-->0){
            int val = pq.top();
            pq.pop();
            ans += val;
            pq.push(ceil(val/3.0));
            //cout <<t<<"\n";
        }
        return ans;
    }
};