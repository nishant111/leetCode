class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rstart, int cstart) {
        int tovis = rows * cols;
        rows--;
        cols--;
        int rtop = rstart-1;
        int rbot = rstart+1;
        int colleft = cstart-1;
        int colright = cstart+1;
        vector< vector<int> > ans;
        int r = rstart;
        int c = cstart;
        while( rtop >= 0 || rbot<=rows || colleft >= 0 || colright <= cols || tovis>0){
            // move right
            while( c <= colright){
                if(c<=cols && r<=rows && r>=0 && c>= 0){
                    tovis--;
                    ans.push_back( {r,c} );
                }
                    c++;
            }
            c--;
            r++;
            // move down
            while( r <= rbot){
                 if(c<=cols && r<=rows && r>=0 && c>= 0 ){
                    tovis--;
                    ans.push_back( {r,c} );
                }
                    r++;
            }
            r--;
            c--;
            //move left
            while( c >= colleft){
                if(c>=0 && r>= 0 && c<=cols && r<=rows){
                    tovis--;
                    ans.push_back( {r,c} );
                }
                    c--;
            }
            c++;
            r--;
            // move up
            while( r >= rtop){
                 if(r>=0 && c>=0 && c<=cols && r<=rows){
                     tovis--;
                    ans.push_back( {r,c} );
                }
                    r--;
            }
            r++;
            c++;
            colright++;
            rbot++;
            colleft--;
            rtop--;
        }
        return ans;
    }
};