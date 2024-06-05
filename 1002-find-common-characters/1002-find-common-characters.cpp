#include<stdio.h>
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp;
        
        for(auto el:words[0]){
            mp[el]++;
        }
        
        for( int i = 1;i<words.size();i++){
            unordered_map<char, int> freq;

            for(auto el:words[i]){
                freq[el]++;
            }
            
            for(auto el:mp){
                mp[el.first] = min(freq[el.first], mp[el.first] );
            }
        }
        
        vector<string> ans;
        for(auto el:mp){
            while( el.second --> 0){
                string t;
                t+=el.first;
                ans.push_back((t));
            }
        }
        return ans;
    }
};