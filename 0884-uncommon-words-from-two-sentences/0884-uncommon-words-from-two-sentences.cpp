class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> words;        
        for( int i = 0;i<s1.size();i++){
            string w="";
            while(i<s1.size() && s1[i] != ' ' ){
                w+=s1[i];
                i++;
            }
            
            words[ w ]++;
        }
        
        for( int i = 0;i<s2.size();i++){
            string w="";
            while(i<s2.size() && s2[i] != ' '){
                w+=s2[i];
                i++;
            }
            
            words[ w ]++;
        }
        
        vector<string> ans;
        for(auto el:words){
            if(el.second == 1){
                ans.push_back(el.first);
            }
        }
        return ans;
    }
};