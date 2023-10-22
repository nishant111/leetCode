class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        q.push({nums[0], 0});
        int sumEndingHere = 0;
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            while(i-q.top().second>k)
                q.pop();
            int decideToExtend = max(q.top().first,0);
            int sumEndingHere = decideToExtend + nums[i];
            ans = max(ans, sumEndingHere);
            q.push({sumEndingHere, i});  
        }
        return ans;
    }
};