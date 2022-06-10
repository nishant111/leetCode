class Solution {
public:
    //lp => last picked
    //u=> sequence undecided
    //i -> sequence increasing
    //d => sequence decreasing
    
    int dfs(vector<int> & rating, int curr, int pickSize, int lp, int seq, vector<vector<vector<int>>> &dp)
    {
        if(pickSize == 3)
        {
            return dp[curr][pickSize][seq] = 1;
        }
        if(curr == rating.size())
        {
            return 0;            
        }
        
        if(dp[curr][pickSize][seq]!= -1)
            return dp[curr][pickSize][seq];
        int ans = 0;
        for(int i = curr;i<rating.size();i++)
        {
            if(lp==-1)
            {
                int tmp = lp;
                lp = rating[i];
                ans += dfs(rating, i+1, pickSize+1, lp, seq, dp);
                lp = tmp;
            }
            else if(lp != -1 && rating[i] > lp && (seq == 0 || seq == 1) )
            {
                int tmp = lp;
                lp = rating[i];
                ans += dfs(rating, i+1, pickSize+1, lp, 1, dp);
                lp = tmp;
            }
            else if(lp!=-1 && rating[i]<lp && (seq == 0 || seq == 2))
            {
                int tmp = lp;
                lp = rating[i];
                ans  += dfs(rating, i+1, pickSize+1, lp, 2, dp);
                lp = tmp;
            }
        }
        return dp[curr][pickSize][seq]=ans;
    }
    int numTeams(vector<int>& rating) {
        int count = 0;
        vector<vector<vector<int>>> dp(rating.size()+1, vector<vector<int>>(4, vector<int>(3, -1)));
        return dfs(rating, 0, 0, -1, 0, dp);
    }
};


