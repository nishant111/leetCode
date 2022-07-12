class Solution {
public:
    bool dfs(int curr, vector<int> &match, vector<int> &sum, int &side)
    {
        if(curr==match.size())
        {
            return  sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3];;
        }
    
        for(int i = 0;i<4;i++)
        {
            if(sum[i] + match[curr] <= side)
            {
                sum[i] += match[curr];
                if(dfs(curr+1, match, sum, side))
                    return true;
                sum[i] -= match[curr];
            }
           
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        vector<int> sum(4, 0);
        int side=0;
        for(auto elem:matchsticks)
        {
            side += elem;
        }
        if(side%4 != 0) return false;
        side =side/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(dfs(0, matchsticks, sum, side))
            return true;
        return false;
    }
};