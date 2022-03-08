class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int bot = m-1;
        int mid;
        while(top<=bot)
        {
            mid = (top + bot)/2;
            if(target > matrix[mid][n-1] )
            {
                top = mid+1;
            }
            else if(target < matrix[mid][0])
            {
                bot = mid-1;
            }
            else
            {
                //found
                break;
            }
        }
        if(top>bot) return false; //invalid case
        int left = 0;
        int right = matrix[mid].size()-1;
        while(left<=right)
        {
            int newmid = (left + right)/2;
            if(target > matrix[mid][newmid])
            {
                left = newmid+1;
            }
            else if(target < matrix[mid][newmid])
            {
                right = newmid-1;
            }
            else if(target == matrix[mid][newmid])
            {
                return true;
            }
        }
        return false;
    }
};















/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int mid;
        int m = matrix.size();
        int n = matrix[0].size();
        int right = (m*n)-1;
        while(left<=right)
        {
            mid = (left+right)/2;
            if(mid/m >= m || mid%m>=n  ) break;
            if(target > matrix[mid/m][mid%m])
            {
                left = mid+1;
            }
            else if(target < matrix[mid/m][mid%m])
            {
                right = mid -1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};


*/
/*class Solution {
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
};*/