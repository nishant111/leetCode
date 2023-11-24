class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0;i<l.size();i++){
            int lb = l[i];
            int rb = r[i];
            vector<int> t;
            for(int j = lb;j<=rb;j++){
                t.push_back(nums[j]);
            }
            sort(t.begin(), t.end());
            bool done=true;
            for(int k = 1;k<t.size();k++){
                if(abs(t[k]-t[k-1])!=abs(t[1]-t[0])){
                    done=false;
                }
            }
            ans.push_back(done);
        }
        return ans;
    }
};