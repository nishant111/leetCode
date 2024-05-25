class Solution {
public:
    vector<string> ans;
    void dfs(string s, unordered_set<string>& wd, int curr, string& currWord){
        if(curr >= s.size()){
            if(currWord.size()>0)
                ans.push_back(currWord);
            return;
        }
        
        for(int i=curr; i<s.size(); i++){
            if(wd.find(s.substr(curr, i-curr+1))!=wd.end())
            {
                int appendIndex = currWord.size()-1;
                //can partition
                if(currWord.size()==0){
                    currWord += s.substr(curr, i-curr+1);
                }
                else{
                    currWord += " " + s.substr(curr, i-curr+1);
                }
                dfs(s, wd, i+1, currWord);
                // undo the currWord for next dont partition case
                currWord = currWord.substr(0, appendIndex-0+1);
                
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wd;
        for(auto el:wordDict){
            wd.insert(el);
        }
        string currWord = "";
        dfs(s, wd, 0, currWord);
        return ans;
    }
};