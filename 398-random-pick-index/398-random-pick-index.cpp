class Solution {
public:
    unordered_map <int, vector<int>> m;
    Solution(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                m[nums[i]].push_back(i);
            }
            else
            {
                m[nums[i]] = {i};
            }
        }
    }
    
    int pick(int target) {
        if(m[target].size()==1)
            return m[target][0];
        else
        {
            int tmp = rand() % m[target].size();
            return m[target][tmp];
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */