class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int l = 0;
        int r = 0;
        while(r<nums.size()){
            vector<int> tmp;
            while(r-l+1<=3){
                if(nums[r]-nums[l]>k)
                    return {};
                tmp.push_back(nums[r]);       
                r++;
            }
            l=r;
            ans.push_back(tmp);
        }
        return ans;
    }
};