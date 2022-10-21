class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set <int> st;
        int start = 0;
        int end = 0;
        for(;end<nums.size() ;end++)
        {
            if(end>start+k)
            {
                st.erase(nums[start]);
                start++;
            }
            if(st.find(nums[end]) != st.end() ) return true;
            st.insert(nums[end]);
            
            
        }
        return false;
    }
};