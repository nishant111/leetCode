class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,  int> freq;
        for(int i= 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int ans = 0;
        for(auto elem:freq){
            if(elem.second>1){
                ans += ((elem.second)*(elem.second-1))/2;
            }
        }
        return ans;
    }
};