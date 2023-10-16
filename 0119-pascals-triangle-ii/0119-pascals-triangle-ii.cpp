class Solution {
public:
    vector<int> getRow(int i) {
        if(i==0) return {1};
        if(i==1) return {1, 1};
        vector<vector<int>> ans;
        for(int x = 0;x<=i;x++){
            if(x==0){
                ans.push_back({1});
                continue;
            }
            if(x==1){
                ans.push_back({1,1});
                continue;
            }
            ans.push_back(vector<int>(x+1));
            for(int c = 0;c<=x;c++){
                if(c==0 || c==x){
                    ans[x][c]= (1);
                }
                else{
                    ans[x][c] = (ans[x-1][c-1] + ans[x-1][c]);
                }
            }
        }
        return ans[i];
    }
};