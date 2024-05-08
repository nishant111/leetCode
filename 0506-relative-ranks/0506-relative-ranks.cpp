class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), greater<int>());
        unordered_map<int, int> ranks;
        for(int i = 0;i<sorted.size();i++){
            ranks[sorted[i]] = i;
        }
        vector<string> ans;
        for(auto elem:score){
            if(ranks[elem]==0){
                ans.push_back("Gold Medal");
            }
            else if(ranks[elem]==1){
                ans.push_back("Silver Medal");
            }
            else if(ranks[elem]==2){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(ranks[elem]+1));
            }
        }
        return ans;
    }
};