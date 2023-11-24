class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        deque<int> dq;
        
        for(auto elem:piles){
            dq.push_back(elem);
        }
        int ans = 0;
        while(dq.size()>0){
            dq.pop_back();
            ans += dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        return ans;
    }
};