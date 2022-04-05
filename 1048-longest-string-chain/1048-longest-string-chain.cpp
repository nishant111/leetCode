class Solution {
public:
    
    int dfs(unordered_set <string>& st, string currWord,
            unordered_map <string, int> &dp)
    {
        if(currWord.size()==1) return 1;
        if(dp[currWord]!= 0) return dp[currWord];
        int ans = 1;
        for(int i = 0;i<currWord.size();i++)
        {
            string newWord = currWord.substr(0, i);
            if(i+1<currWord.size())
                newWord += currWord.substr(i+1, currWord.size() - i);
            if(st.find(newWord) != st.end())
            {
                ans = max(ans, (1+ dfs(st, newWord, dp)));
            }
        }
        return dp[currWord] = ans;
    }
    int longestStrChain(vector<string>& words) {
        int ans = INT_MIN;
        unordered_set <string> st;
        unordered_map <string, int> dp;
        for(auto elem:words)
        {
            st.insert(elem);
        }
        
        for(int i = 0;i<words.size();i++)
        {
            ans = max(ans, dfs(st, words[i], dp));
        }
        return ans;
    }
};