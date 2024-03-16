class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0;
        int ans = INT_MIN;
        unordered_map<int, int> mp;
        for(int i = 0;i<nums.size();i++){
            int elem=nums[i];
            if(elem == 0)
                count --;
            else
                count ++;
            if(mp.find(count)!=mp.end()){
                ans = max(ans, i- (mp[count]+1) + 1 );
            }
            else
                mp[count] = i;
            if(count == 0){
                ans = max(ans, i+1);
            }
        }
        return ans==INT_MIN?0:ans;
    }
};