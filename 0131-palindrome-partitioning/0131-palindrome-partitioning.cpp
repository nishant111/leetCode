class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(int start, int end, string &s){
        while(start<=end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void dfs(string s, int curr,  vector<string> &currPali){
        if(curr == s.size()){
            ans.push_back(currPali);
        }
        
        for(int i = curr;i<s.size();i++){
            if(isPalindrome(curr, i, s)){
                currPali.push_back(s.substr(curr, i-curr+1));
                dfs(s, i+1, currPali);
                currPali.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> currPali;
        dfs(s, 0, currPali);
        return ans;
    }
};