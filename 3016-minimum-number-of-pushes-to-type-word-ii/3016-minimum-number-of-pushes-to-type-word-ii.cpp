class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto el:word){
            freq[el-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int count = 0;
        int ans = 0;
        for(int i = 0;i<26;i++){
            int el = freq[i];
            if(el==0) break;
            count++;
            int offset = (count/8);
            if( (count)%8 != 0)
                ans += el * (offset+1);
            else{
                ans += el * (offset);
            }
        }
        return ans;
    }
};