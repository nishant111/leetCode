class Solution {
public:
    int dfs(vector<int>& nums, vector<int>& currSet, int k, int curr){
        
        if(curr == nums.size()){
            if(currSet.size()> 0)
                return 1;
            return 0;
        }
        
        int count = 0;
        bool canTake = true;
        //take
        for(auto elem:currSet){
            if(abs(elem-nums[curr])==k)
                canTake = false;
        }
        if(canTake){
            currSet.push_back(nums[curr]);
            count += dfs(nums, currSet, k, curr+1);
            currSet.pop_back();
        }
        //dont take
        count += dfs(nums, currSet, k, curr+1);
        return count;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> currSet;
        return dfs(nums, currSet, k, 0);
    }
};