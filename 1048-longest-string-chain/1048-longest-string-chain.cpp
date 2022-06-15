class Solution {
public:
    
    int dfs(vector<string>& words, string curr, unordered_set<string> & st, unordered_map<string, int>& dp)
    {
        if(curr.size() == 1)
            return dp[curr] = 1;
        int ans = 1;
        if(dp.find(curr)!=dp.end()) return dp[curr];
        for(int i = curr.size()-1;i>=0;i--)
        {
            string toFind;
            if(i == curr.size()-1)
            {
                toFind = curr.substr(0, i);
            }
            else if(i==0)
            {
                toFind = curr.substr(1, curr.size());
            }
            else
            {
                toFind = curr.substr(0, i) + curr.substr(i+1, curr.size()-1 - (i+1) + 1);
            }
            
            if(st.find(toFind) != st.end())
            {
                ans = max(ans, 1+ dfs(words, toFind, st, dp));
            }
        }
        return dp[curr] = ans;
        
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_set<string> m;
        unordered_map<string, int> dp;
        for(int i = 0;i<words.size();i++)
        {
            m.insert({words[i]});
        }
        int ans = INT_MIN;
        for(int i = 0;i<words.size();i++)
        {
            ans = max(ans, dfs(words, words[i] , m, dp));
        }
        return ans;
    }
};




























/*
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
};*/