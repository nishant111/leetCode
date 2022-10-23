class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
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
};