class Solution {
public:
vector<vector<vector<int>>>dp;
long long MOD = 1000000007;

bool isValidAfterCut(vector<string>&pizza, int startRow, int startCol, int endRow, int endCol)
    {
        for (int i = startRow; i <= endRow; i++)
        {
            for (int j = startCol; j <= endCol; j++)
            {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    long long dfs(vector<string> &pizza, int k, int row1, int col1, int cutCount) {
        
        //cout<<"dfs of " << row1 << ":" << col1 <<"\n";
        if(cutCount == k-1)
        {
            // base case
            return 1;
        }
        if(dp[row1][col1][cutCount]!=-1) return dp[row1][col1][cutCount];
        long long ans = 0;
        for(int currCut = row1;currCut<pizza.size()-1;currCut++)
        {
            if((isValidAfterCut(pizza, row1, col1, currCut, pizza[0].size()) == true) &&
            (isValidAfterCut(pizza, currCut+1, col1, pizza.size()-1, pizza[0].size()-1)) ) {
                int horWays =  dfs(pizza, k, currCut+1, col1, cutCount+1);
                ans = (ans+horWays) %MOD;
            }
        }

        for(int currCut = col1;currCut<pizza[0].size()-1;currCut++)
        {
            if((isValidAfterCut(pizza, row1,col1, pizza.size()-1, currCut) == true) &&
             (isValidAfterCut(pizza, row1, currCut+1, pizza.size()-1, pizza[0].size()-1))){

                int verWays = dfs(pizza, k, row1, currCut+1, cutCount+1);
                ans = (ans + verWays) %MOD;
            }
        }
        return dp[row1][col1][cutCount] = (int)ans;

    }
   
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        dp. resize(m, vector(n, vector<int>(k, -1)));
       

        return dfs(pizza, k, 0, 0, 0);
    }
};