class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> zeroLoss;
        unordered_set<int> oneLoss;
        unordered_set<int> moreLoss;
        
        for(auto elem:matches){
            int winner = elem[0];
            int loser = elem[1];
            if(zeroLoss.find(loser) != zeroLoss.end()){
                zeroLoss.erase(loser);
                oneLoss.insert(loser);
            }
            else if(oneLoss.find(loser) != oneLoss.end()){
                oneLoss.erase(loser);
                moreLoss.insert(loser);
            }
            else if(moreLoss.find(loser)!=moreLoss.end()){
                
            }
            else{
                oneLoss.insert(loser);
            }
            if(oneLoss.find(winner)==oneLoss.end() && 
               moreLoss.find(winner)==moreLoss.end()){
                zeroLoss.insert(winner);
            }
        }
        vector<int> z;
        vector<int> o;
        vector<vector<int>> ans;
        for(auto elem:zeroLoss){
            z.push_back(elem);
        }
        for(auto elem:oneLoss){
            o.push_back(elem);
        }
        sort(z.begin(), z.end());
        sort(o.begin(), o.end());
        ans.push_back(z);
        ans.push_back(o);
        return ans;
    }
};