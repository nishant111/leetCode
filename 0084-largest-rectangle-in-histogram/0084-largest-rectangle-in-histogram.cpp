class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> svr(heights.size()); //smaller value on right
        vector<int> svl(heights.size());
        int mini = INT_MAX;
        stack<int> st;
        for(int i = 0;i<heights.size();i++){
            if(i==0)
                svl[i]=0;
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                svl[i]=0;
            }
            else{
                svl[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = heights.size()-1;i>=0;i--){
            if(i==heights.size()-1)
                svr[i]=heights.size()-1;
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                svr[i]=heights.size()-1;
            }
            else{
                svr[i]=st.top()-1;
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0;i<heights.size();i++){
            ans = max(heights[i]*((svr[i])-(svl[i])+1), ans);
        }
        return ans;
                    
    }
};