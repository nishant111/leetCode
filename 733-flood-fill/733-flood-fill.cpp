class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int origColor)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) //|| image[sr][sc] == newColor)
            return;
        else if(image[sr][sc] == origColor )
        {
            image[sr][sc]=newColor;
            cout <<"Setting " << sr << " "<<sc <<"to "<< newColor;
            dfs(image, sr-1, sc, newColor, origColor);
            dfs(image, sr+1, sc, newColor, origColor);
            dfs(image, sr, sc-1, newColor, origColor);
            dfs(image, sr, sc+1, newColor, origColor);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        /*for(int i = 0;i<image.size();i++)
        {
            for(int j = 0;j<image[0].size();j++)
            {
                imageCopy[i][j] = image[i][j];
            }
        }*/
        if(image[sr][sc]!=newColor)
          dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};