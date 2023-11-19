class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int r = nums.size()-1;
        int op = 0;
        priority_queue<pair<int, int>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto el:mp)
        {
            pq.push(el);
        }
        int ans = 0;
        while(pq.size()>1){
            auto t = pq.top();
            pq.pop();
            ans += t.second;
            
            auto t2 = pq.top();
            pq.pop();
            t2.second+=t.second;
            pq.push(t2);
        }
        return ans;
    }
};