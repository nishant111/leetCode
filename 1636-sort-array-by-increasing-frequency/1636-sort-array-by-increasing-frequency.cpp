class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int> &b ){
        if(a.first<b.first){
            return true;
        }
        else if(a.first>b.first){
            return false;
        }
        else{
            return a.second>b.second;
        }
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();){
            int count = 1;
            int j = i+1;
            for(;j<nums.size();j++){
                if(nums[j]==nums[i]){
                    count++;
                }
                else{
                    break;
                }
            }
            s.push_back({count, nums[i]});
            i=j;
        }
        sort(s.begin(), s.end(), comp);
        vector<int> ans;
        for(auto el:s){
            int freq = el.first;
            while(freq>0){
                ans.push_back(el.second);
                freq--;
            }
        }
        
        return ans;
    }
};