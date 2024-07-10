class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int i = 0;i<nums.size()-2;i++){
            for(int j = i+1;j<nums.size();j++ ){
                int to_find = (nums[i] + nums[j])*-1;
                if(mp.find(to_find) != mp.end() && mp[to_find]!=i && mp[to_find]!=j && mp[to_find]>j){
                    ans.push_back({nums[i], nums[j], to_find});
                }
                while(j<nums.size()-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1]){
                    i++;
                }
        }
        return ans;
    }
};