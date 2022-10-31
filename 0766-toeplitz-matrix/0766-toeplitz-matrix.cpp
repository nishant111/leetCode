class Solution {
public:
    /*
    Must go through below follow up answer:
    https://leetcode.com/problems/toeplitz-matrix/discuss/516366/Python-Follow-Up-1-with-Explanation-and-Diagrams
    Conclusion Algo 1:
    Init Steps => create ExpectedDequeue, row=0 
    1.load row in ExpectedDequeue(1234)
    2. pop_back elem in ExpectedDequeue, push_front next row first elem, ExpectedDequeue becomes [5123]
    3. compare with row++;
    4. repeat step 2 & 3 until row<matrix.size();
    
    https://leetcode.com/problems/toeplitz-matrix/discuss/271388/Java-Solution-for-Follow-Up-1-and-2
    Conclusion:
    Split matrix into submatrices with one row overlapping.
    1234
    3153
    breaks into 
    12  23  34
    31  15  53
    
    if you dont overlap it will give wrong result(true)
    12  34
    31  53
    
    After breaking run Conclusion Algo 1 on all submatrices
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