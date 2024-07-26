class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9' , "wxyz"}
    };
    
    void dfs(string digits, int curr, string currString, vector<string> &ans){
        if(curr>=digits.size()){
            ans.push_back(currString);
        }
        for(auto el:mp[digits[curr]]){
            dfs(digits, curr+1, currString+el, ans);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> ans;
        dfs(digits, 0, "", ans);
        return ans;
    }
};