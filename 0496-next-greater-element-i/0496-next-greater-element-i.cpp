class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto elem:nums1){
            m[elem] = -1;
        }
        stack<int> st;
        for(int i = nums2.size()-1;i>=0;i--){
            if(st.empty()){
                m[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
                if(st.top()>nums2[i]){
                    m[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }
                else{
                    while(!st.empty() && st.top()<nums2[i]){
                        st.pop();
                    }
                    if(!st.empty() && st.top()>nums2[i]){
                         m[nums2[i]]=st.top();
                    }
                    st.push(nums2[i]);
                }
            }
        }
        for(int i = 0;i<nums1.size();i++){
            nums1[i] = m[nums1[i]];
        }
        return nums1;
    }
};