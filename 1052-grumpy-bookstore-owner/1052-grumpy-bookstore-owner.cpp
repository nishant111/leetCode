class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0;
        int r = minutes-1;
        int grumpyWindowSum = 0; //window sum
        int ret = 0;
        for(int i = 0;i<customers.size();i++){
            if(!grumpy[i])
                ret += customers[i];
        }
        for(int i = 0;i<=r;i++){
            grumpyWindowSum += customers[i] * grumpy[i];
        }
        int ans = grumpyWindowSum;
        while(r+1<customers.size()){
            grumpyWindowSum -= customers[l] * grumpy[l];
            grumpyWindowSum += customers[r+1] * grumpy[r+1];
            ans = max(grumpyWindowSum, ans);
            l++;
            r++;
        }
        return ret + ans;
    }
};