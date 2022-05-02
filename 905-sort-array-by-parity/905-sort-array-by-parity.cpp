class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = nums.size()-1;
        vector<int> ans = nums;
        int ev = 0;
        while(ev < odd)
        {
            if(ans[ev]%2!=0)
            {
                swap(ans[ev], ans[odd]);
                odd--;
            }
            else if(ans[ev]%2==0)
            {
                ev++;
            }
        }
        return ans;
        
    }
};