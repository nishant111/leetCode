class Solution {
public:
    /*
    Must go through below follow up answer:
    https://leetcode.com/problems/toeplitz-matrix/discuss/516366/Python-Follow-Up-1-with-Explanation-and-Diagrams'=
    https://leetcode.com/problems/toeplitz-matrix/discuss/271388/Java-Solution-for-Follow-Up-1-and-2
    */
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size()-1;
        int c= 0;
        
        while(r>0)
        {
            int elem = matrix[r][c];
            int tmpr = r;
            while(tmpr<matrix.size() && c<matrix[0].size())
            {
                if(matrix[tmpr][c]!=elem)
                    return false;
                tmpr++;c++;
            }
            r--;
            c=0;
        }
        while(c<matrix[0].size())
        {
            int elem = matrix[r][c];
            int tmpc = c;
            while(tmpc<matrix[0].size()&&r<matrix.size())
            {
                if(matrix[r][tmpc]!=elem)
                    return false;
                r++;tmpc++;
            }
            c++;
            r=0;
        }
        return true;
    }
};