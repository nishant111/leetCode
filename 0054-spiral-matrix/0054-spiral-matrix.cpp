class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int r, int c, vector<int>&ans, char dir ){
        if(r<0||c<0||r>=matrix.size()||c>=matrix[0].size())
        {
            return;
        }
        if(matrix[r][c]==-101) return;
        ans.push_back(matrix[r][c]);
        matrix[r][c]=-101;
        if(dir=='u'){
            dfs(matrix, r-1, c, ans, 'u');
        }

        dfs(matrix, r, c+1, ans, 'r');
        dfs(matrix, r+1, c, ans, 'd');
        dfs(matrix, r, c-1, ans, 'l');
        dfs(matrix, r-1, c, ans, 'u');
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        //dfs(matrix, 0, 0, ans, 'r');
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        while(ans.size()<m*n){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[up][i]);
            }
            for(int i=up+1;i<=down;i++){
                ans.push_back(matrix[i][right]);
            }
            if(up!=down){
                for(int i=right-1;i>=left;i--){
                    ans.push_back(matrix[down][i]);
                }
            }
            if(left!=right){
            for(int i=down-1;i>up;i--){
                ans.push_back(matrix[i][left]);
            }
            }
            left++;
            right--;
            up++;
            down--;
        }


        return ans;
    }
};