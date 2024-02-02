class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1;i<=9;i++){
            int tmp = i;
            for(int j = i + 1;j<=9;j++){
                tmp = tmp*10+j;
                if(tmp>=low && tmp<=high){
                    ans.push_back(tmp);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};