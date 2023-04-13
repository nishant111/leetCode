class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int pu = 0;
        int po = 0;

        stack<int> st;

        while(po<popped.size()) {
            if(!st.empty() && st.top() == popped[po]) {
                st.pop();
                po++;
            }
            else if(pu<pushed.size()){
                st.push(pushed[pu++]);
            }
            else if(!st.empty() && st.top()!=popped[po] && pu==pushed.size())
            return false;
            
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};