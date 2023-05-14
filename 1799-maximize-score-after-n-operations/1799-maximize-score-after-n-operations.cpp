class Solution {
public:
    bool isBitSet(int& num, int bitIdx)
    {
        //(1 << bitIdx) => only the ith bit set, rest all 0'S
        if ((num & (1 << bitIdx)) != 0) 
            return true;
        return false;
    }
    void setBit(int& num, int bitIdx)
    {
        num = num | (1 << bitIdx);
    }
    int solve(vector<int>&nums, unordered_map<int, int>& cache, int operation, int mask)
    {   
        if(cache.find(mask)!=cache.end())
            return cache[mask];
        int maxScore = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            //if (visited[i]) continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                //if (visited[j]) continue;
                //visited[i] = true;
                //visited[j] = true;
                if(mask & (1<<i) || mask&(1<<j)) continue;
                int newMask = mask | (1<<i) | (1<<j);
                //=====================================================================
                int currScore = operation * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, cache, operation + 1, newMask);
                int totalScore = currScore + nextMaxScore;
                maxScore = max(maxScore, totalScore);
                //======================================================================
                //visited[i] = false;
                //visited[j] = false;
            }
        }
        return cache[mask]=maxScore; //store the result
    }
    int maxScore(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool>visited(n, false);
        unordered_map<int, int>cache;
        int ans = solve(nums, cache, 1, 0);
        return ans;
        
    }
};

/*class Solution {
public:
    int dfs(vector<int> nums, int curr, vector<bool>& vis){
        while(curr<nums.size() && vis[curr]==true)curr++;
        if(curr==nums.size())
            return 0;
        int ans = 0;
        for(int i = curr+1;i<nums.size();i++){
            if(vis[i]==true)
                continue;
            vis[curr]=vis[i]=true;
            int currScore = (curr+1) * (gcd(nums[curr], nums[i]));
            int nextScore = dfs(nums, curr+1, vis);
            ans = max(ans, currScore+nextScore );
            vis[curr]=vis[i]=false;
        }
        return ans;
    }
    int maxScore(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        return dfs(nums, 0, vis);
    }
};*/