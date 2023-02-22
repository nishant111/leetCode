class Solution {
public:
    // break array into days partitions such that 
    // maximum of sum of all partitions in minimized.
    int ans = INT_MAX;
    int dfs(vector<int> &weights, int days, int curr, int prevSum){
        if(days == 0 && curr == weights.size())
        {
            return prevSum;
        }
        if(days == 0 && curr < weights.size())
        {
            return INT_MAX;
        }
        int ans=INT_MAX;
        int sum = 0;
        for(int i = curr;i<weights.size();i++){
            sum += weights[i];
            ans = min(dfs(weights, days-1, i+1, max(sum, prevSum)), ans);
        }
        return ans;
    }
    bool possible(vector<int>& weights,int barrier, int days ) {
        int currDays = 1;
        int currSum = 0;
        for(auto elem:weights){
            if(currSum+elem > barrier){
                currDays++;
                currSum = elem;
            }
            else{
                currSum += elem;
            }
        }
        if(currDays>days) return false;
        else return true;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum;
        //return dfs(weights, days, 0, 0);

        // dfs is TLE O(N*Days)
        int maxi =INT_MIN;
        int right = 0;
        for(auto elem:weights){
            if(elem>maxi)
                maxi=elem;
            right += elem;
        }
        int ans = right;
        int left = maxi; // even if 100 days are given you will still carry the maximum weight;
        // if 1 day is given you have to carry all hence right is sum
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(possible(weights, mid, days)){
                ans = mid;
                right = mid-1; // answer can be somewhere to right
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;

    }
};