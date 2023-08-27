class Solution {
public:
    bool dfs(vector<int> &stones, int curr, int lastJump, vector<vector<int>>& dp){
        if(curr==stones.size()-1){
            //reached
            return true;
        }
        if(dp[curr][lastJump]!=-1) return dp[curr][lastJump];
        vector<int> pj; //possibleJumps;
        if(lastJump == 0){
            // it is the start
            pj = {1};
        }
        else{
            pj = {lastJump-1, lastJump, lastJump+1};
        }

        for(int i = 0;i<pj.size();i++){
            int jump = pj[i];
            int j = curr+1;
            while(j<stones.size() && stones[j] < stones[curr]+jump){ 
                j++;
            }
            if(j==stones.size()) return false; // reached beyond last, no point of trying now
            if(stones[curr]+jump == stones[j]){
               // can jump here
               if(dfs(stones, j, jump, dp))
                return dp[curr][lastJump] = true;
            }
        }
        return dp[curr][lastJump] = false;
    }
    bool canCross(vector<int>& stones) {
        int m = stones.size()-1;
        vector<vector<int>> dp(stones.size(),vector<int> (2000, -1));
        return dfs(stones, 0, 0, dp);
    }
};