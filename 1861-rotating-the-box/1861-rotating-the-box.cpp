class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for( int i = box.size()-1;i>=0;i--){
            int restHereCol = -1;
            for( int j = box[i].size()-1;j>=0;j--){
                if( box[i][j] == '.' && restHereCol == -1){
                    restHereCol=j;
                }
                else if( box[i][j] == '#' && restHereCol != -1){
                    cout<<i<<" "<<j<<'\n';
                    box[i][j] = '.';
                    box[i][restHereCol--] = '#';
                }
                else if( box[i][j] == '*' ){
                    restHereCol=-1;
                }
            }
        }
        int r = box.size();
        int c = box[0].size();
        vector<vector<char>> ans(c, vector<char>(r) );
        for(int j = 0;j<box[0].size();j++){
             for(int i=box.size()-1;i>=0;i--){
                ans[j][box.size()-1-i] = box[i][j];
            }
        }
        return ans;
    }
};