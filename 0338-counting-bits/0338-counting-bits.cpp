class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0;i<=n;i++){
            int curr = i;
            int count =0;
            while(curr>0){
                if((curr & 1)==1)
                    count++;
                curr=curr>>1;
            }
            ans.push_back(count);
        }
        return ans;
    }
};