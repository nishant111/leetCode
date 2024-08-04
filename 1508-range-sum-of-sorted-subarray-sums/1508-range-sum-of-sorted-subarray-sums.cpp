class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sa;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum = 0;
            for(int j = i;j<nums.size();j++){
                sum += nums[j];
                sa.push_back(sum);
            }
        }
        sort(sa.begin(), sa.end());
        int ans = 0;
        for(int i = left-1;i<=right-1;i++){
            ans = (ans + sa[i]) % 1000000007;
        }
        return ans;
    }
};