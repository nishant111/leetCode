class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(auto elem:word1){
            freq1[elem-'a']++;
        }
        for(auto elem:word2){
            freq2[elem-'a']++;
        }
        
        for(auto elem:word2){
            if(freq1[elem-'a']==0){
                return false;
            }
        }
        for(auto elem:word1){
            if(freq2[elem-'a']==0){
                return false;
            }
        }
        sort(freq1.begin(), freq1.end() );
        sort(freq2.begin(), freq2.end() );
        if(freq1!=freq2) return false;
        return true;
    }
};