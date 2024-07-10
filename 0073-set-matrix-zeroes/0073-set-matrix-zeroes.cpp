class Solution {
public:
    void setCol0(vector<vector<int>>& matrix, int col){
        for(int i = 0;i<matrix.size();i++){
            matrix[i][col] = 0;
        }
        return;
    }
    
    void setRow0(vector<vector<int>>& matrix, int row){
        for(int i = 0;i<matrix[0].size();i++){
            matrix[row][i] = 0;
        }
        return;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool fc0 = false;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    if(i==0 && j == 0){
                        fc0=true;
                    }
                    else if(j == 0)
                        fc0 = true;
                    else{
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i = 1;i<matrix[0].size();i++){
            if(matrix[0][i] == 0){
                setCol0(matrix, i);
            }
        }
        for(int i = 0;i<matrix.size();i++){
            if(matrix[i][0] == 0){
                setRow0(matrix, i);
            }
        }
        if(fc0 == true){
             setCol0(matrix, 0);
        }
            
    }
};