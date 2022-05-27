#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int longestSubarray(vector<int>& nums, int limit) {
        int winStart = 0;
        int winEnd = 0;
        
        multiset<int> st;
        int ans = INT_MIN;
        while(winStart <= winEnd && winEnd < nums.size())
        {
            st.insert(nums[winEnd]);
            auto mini = st.begin();
            auto maxi = st.rbegin();
            if(abs((*maxi) - (*mini)) <= limit )
            {
                ans = max(winEnd - winStart+1, ans);
                winEnd++;
            }
            else
            {
                while(winStart <= winEnd && abs((*maxi) - (*mini)) > limit )
                {
                    st.erase(st.find(nums[winStart]) );
                    mini = st.begin();
                    maxi = st.rbegin();
                    winStart++;
                }
                winEnd++;
            }
        }
        return ans;
        
        
        
        
        
        /*
        Cannot use P queue because random deletion is not possible in Priority queue
        priority_queue <int> pq_max;
        priority_queue <int,  vector<int> , greater<int>> pq_min;
        while(winStart<=winEnd)
        {
            pq_max.push(nums[winEnd]);
            pq_min.push(nums[winEnd]);
            
            if(pq_max.top() - pq_min.top()<=limit)
            {
                winEnd++;
            }
            else
            {
                pq_max.    
            }
                        
        }
        */
    }
};