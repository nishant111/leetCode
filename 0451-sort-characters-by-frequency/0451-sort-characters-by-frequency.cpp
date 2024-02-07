class Solution {
public:
    static bool comp(pair<int,char> &A, pair<int,char> &B){
        return A.first>B.first;
    }
    string frequencySort(string s) {
        vector<pair<int, char>> freq(128,{0,0});
        
        for(auto elem:s){
            freq[elem-'0'].first++;
            freq[elem-'0'].second = elem;
        }
         
        sort(freq.begin(), freq.end(), comp);
        string ans="";
        for(auto elem:freq){
            while(elem.first>0){
                ans += elem.second;
                elem.first--;
            }
        }
        return ans;
    }
};