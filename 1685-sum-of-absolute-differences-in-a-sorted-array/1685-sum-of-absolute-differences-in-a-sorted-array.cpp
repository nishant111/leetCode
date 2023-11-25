class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> suffix(nums.size());
        vector<int> prefix(nums.size());
        prefix[0]=nums[0];
        suffix[nums.size()-1]=nums[nums.size()-1];
        int j = nums.size()-2;
        for(int i = 1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
            suffix[j] = suffix[j+1]+nums[j];
            j--;
        }
        vector<int> result(nums.size());
        for(int i = 0;i<nums.size();i++){
            result[i] = ((nums[i]*i)-prefix[i]) + (suffix[i] - (nums[i] * (nums.size()-1-i) ) );
        }
        return result;
    }
};