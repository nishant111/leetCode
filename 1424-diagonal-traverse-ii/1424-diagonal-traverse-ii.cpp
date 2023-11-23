class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxid=INT_MIN;
        int r = nums.size()-1;
        unordered_map<int, vector<int>> mp;
        while(r>=0){
            int c=0;
            while(c<nums[r].size()){
                int id = r+c;
                mp[id].push_back(nums[r][c]);
                c++;
                if(id>maxid){
                    maxid=id;
                }
            }
            r--;
        }
        int i = 0;
        vector<int> ans;
        while(i<=maxid){
            for(auto el:mp[i]){
                ans.push_back(el);
            }
            i++;
        }
        return ans;
    }
};