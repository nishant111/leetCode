class Solution {
public:
    int dfs(vector<vector<int>>& books, int curr, int remWidth, int maxHForCurrShelf, vector<vector<int>>& dp ){
        if(curr == books.size()){
            return maxHForCurrShelf;;
        }
        if(dp[curr][remWidth] != -1) return dp[curr][remWidth];
        // keep on current Shelf
        int op1 = INT_MAX;
        int op2 = INT_MAX;
        if(remWidth > 0 && remWidth >= books[curr][0]){
            // can keep only if space is there
            op1 = dfs( books, curr+1, remWidth-books[curr][0], books[curr][1]>maxHForCurrShelf?books[curr][1]:maxHForCurrShelf, dp);
        }
        
        // keep on next shelf
        op2 = maxHForCurrShelf + dfs(books, curr+1, sw-books[curr][0], books[curr][1], dp);
        
        return dp[curr][remWidth] = min(op1, op2);
    }
    
    int sw = 0;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        sw = shelfWidth;
        vector<vector<int>> dp(books.size()+1, vector<int> (shelfWidth, -1));
        return dfs(books, 1, shelfWidth-books[0][0], books[0][1], dp);  // placed first book on first shelf and now recurse all options
    }
};