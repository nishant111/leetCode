class Solution {
public:
    vector<int> findErrorNums1(vector<int>& nums) {
        // O(n) time and O(n) space
        unordered_set <int> st;
        vector<int> ans;
        for(auto elem:nums)
        {
            if(st.find(elem)!= st.end())
                ans.push_back(elem);
            st.insert(elem);
        }
        
        for(int i = 1;i<=nums.size();i++)
        {
            if(st.find(i) == st.end())
                ans.push_back(i);
        }
        return ans;
    }
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]) );
            else
                nums[abs(nums[i])-1] *= -1;
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};