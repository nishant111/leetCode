class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> st;
        int currMin = nums[0];
        for(auto elem:nums){
            while(!st.empty() && elem>=st.top().first)
                st.pop();
            
            if(!st.empty() && elem>st.top().second && elem<st.top().first)
                return true;
            
            st.push({elem, currMin});
            currMin = min(currMin, elem);
        }
        return false;
    }
};