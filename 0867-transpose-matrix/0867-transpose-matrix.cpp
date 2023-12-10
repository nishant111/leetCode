class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> t(n);
        
        for(int i = 0;i<matrix[0].size();i++){
            for(int j = 0;j<matrix.size();j++){
                t[i].push_back(matrix[j][i]);
            }
        }
        return t;
    }
};