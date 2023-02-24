class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int mini =INT_MAX;
        for(auto elem:nums) {
            int i;
            if(elem%2 != 0)
            {
                i=(elem*2);
            }
            else
            {
                i=(elem);
            }
            mini = min(mini, i);
            q.push(i);
        }
        int ans = INT_MAX;
        while(q.top()%2 == 0){
            int curr = q.top();
            q.pop();
            ans = min(ans,curr - mini);
            curr = curr/2;
            mini = min(curr, mini);
            q.push(curr);
        }
        return min(ans, q.top()-mini);
    }
};