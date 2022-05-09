class Solution {
public:
    unordered_map <char, string> m;
    void createMapping()
    {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
    }
   
    void dfs(string digits, string combo, int curr, vector<string> &ans)
    {
        if(combo.size() == digits.size())
        {
            ans.push_back(combo);
            return;
        }
        string letter = m[digits[curr]];
        for(int i = 0;i<letter.size();i++)
        {
            dfs(digits, combo + letter[i], curr+1, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        createMapping();
        string combo = "";
        if(digits.size()==0)
            return ans;
        dfs(digits, combo, 0, ans);
        return ans;
    }
};