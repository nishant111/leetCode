class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> psum; //prefix sum vector
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
                
            }
            else{
                nums[i] = 1;
                sum += nums[i];
                //psum.push_back(sum);
            }
            psum.push_back(sum);
        }
        
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto elem:psum){
            if(elem == k){
                ans++;
            }
            mp[elem]++;
            if(mp.find(elem-k)!=mp.end()){
                ans += mp[elem-k];
            }
        }
        return ans;
    }
};