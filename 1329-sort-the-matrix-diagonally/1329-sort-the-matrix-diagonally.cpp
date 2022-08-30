class Solution {
public:
    
    void extract(int row, int col, vector<vector<int>>& mat, vector<int>& arr)
    {
         int r = row;
        int c = col;
        while(r<mat.size() && c<mat[0].size())
        {
            arr.push_back(mat[r++][c++]);
        }
    }
    
    void place(int row, int col, vector<vector<int>>& mat, vector<int>& arr)
    {
        int r = row;
        int c = col;
        int i = 0;
        while(r<mat.size() && c<mat[0].size() && i<arr.size())
        {
            mat[r++][c++] = arr[i++];
        }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = 0;
        for(int i = row;i>=0;i--)
        {
            vector<int> arr;
            extract(i, col, mat, arr);
            sort(arr.begin(),arr.end());
            place(i, col, mat, arr);
        }
        
        row = 0;
        col = 1;
        for(int i = col;i<mat[0].size();i++)
        {
            vector<int> arr;
            extract(row, i, mat, arr);
            sort(arr.begin(),arr.end());
            place(row, i, mat, arr);
        }
        return mat;
        
    }
};