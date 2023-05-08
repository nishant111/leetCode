class Solution {
public:
    int sum(vector<vector<int>>& mat, int r, int c, bool skip){
        int ret = 0 ;
        while(r<mat.size() && (c<mat.size() && c>=0)){
            if(skip && r==c){
                r++;
                c--;
                continue;
            }
            ret += mat[r][c];
            if(skip){
                r++;
                c--;
            }
            else{
                r++;c++;
            }
        }
        return ret;
    }
    int diagonalSum(vector<vector<int>>& mat) {
        int lsum = sum(mat, 0, 0, false);
        int rsum = sum(mat, 0, mat[0].size()-1, true);
        return lsum + rsum;
    }
};