class Solution {
public:
    /* At each character we have 2 choices either to include it in the palindrome or start a new
    palindrome, Hence 2^n choices and each time we take O(n) to check if its a plaindrome hence
    O(2^n * n)*/
    bool isP( string &s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            else{
                r--;
                l++;
            }
        }
        return true;
    }
    
    void dfs( string s, int idx, vector<string>& curr, vector<vector<string>>& ans){
        
        if(idx == s.size()){
            // no more choices
            ans.push_back(curr);
            return;
        }
        
        for(int i = idx;i<s.size();i++){
            if(isP(s, idx, i)){
                curr.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1, curr, ans);
                curr.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> currList;
        dfs( s, 0, currList, ans);
        return ans;
    }
};