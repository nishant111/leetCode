class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0;i<matrix.size();i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][matrix[0].size()-1])
            {
                int mid;
                int left = 0;
                int right = matrix[i].size()-1;
                while(left <= right)
                {
                    mid = (left + right)/2;
                    if(target > matrix[i][mid])
                    {
                        left = mid+1;
                    }
                    else if(target < matrix[i][mid])
                    {
                        right = mid-1;
                    }
                    else if(target == matrix[i][mid])
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};