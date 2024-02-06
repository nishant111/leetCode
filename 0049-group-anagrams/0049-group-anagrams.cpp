class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        
        
        for(auto str:strs){
            vector<int> freq(26,0);
            for(auto elem:str){
                freq[elem-'a']++;
            }
            mp[freq].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto elem:mp){
            ans.push_back(elem.second);
        }
        return ans;
    }
};