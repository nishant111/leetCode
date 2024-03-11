class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,pair<int,int>> freq;
        for(int i = 0;i<s.size();i++){
            char elem = s[i];
            freq[elem].first++;
            freq[elem].second = i;
        }
        string ans = "";
        for(auto elem:order){
            while(freq[elem].first-->0){
                ans += elem;
            }
        }
        vector<pair<int, char>> t;
        for(auto elem:freq){
            while(elem.second.first-->0){
                t.push_back({elem.second.second, elem.first});
            }
        }
        sort(t.begin(), t.end());
        for(auto elem:t){
            ans += elem.second;
        }
        return ans;
    }
};