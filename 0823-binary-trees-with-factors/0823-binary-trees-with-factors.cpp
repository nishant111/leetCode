class Solution {
public:
    int MOD = 1000000007;
    unordered_set<int> s;
    unordered_map<int, long long> dp;
    long long getTrees(int root, vector<int>& arr){
        if(dp.count(root)) return dp[root];
        long long count = 1;
        for(auto el:arr){
            if(el > root) continue;
            if((root % el)!=0) continue;
            
            if((root%el)==0 && s.find(root/el)!=s.end())
            {
                count += (getTrees(el, arr) * getTrees(root/el, arr));
                count = count%MOD;
            }
            
        }
        return dp[root] = count;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        s.insert(arr.begin(), arr.end());
        int ans = 0;
        for(auto elem:arr){
            ans += getTrees(elem, arr);
            ans %= MOD;
        }
        return ans;
    }
};