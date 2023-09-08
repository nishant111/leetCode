class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);/* = {{1}};
        if (numRows == 1){
            return ans
        }
        if(numRows == 2){
            ans.push_back({1,1});
        }*/
        
        for(int i = 1;i<=numRows;i++){
            for(int j = 0;j<i;j++){
                if(j==0){
                    ans[i-1].push_back(1);         
                }
                else if(j==i-1){
                    ans[i-1].push_back(1);
                }
                else{
                    ans[i-1].push_back(ans[i-2][j-1] + ans[i-2][j] );
                }
            }
        }
        return ans;
    }
};