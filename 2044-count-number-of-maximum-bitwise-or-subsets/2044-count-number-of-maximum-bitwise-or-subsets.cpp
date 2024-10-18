class Solution {
public:
    int maxi = INT_MIN;
    void dfs( vector<int> &nums, int currOr, int curr, int& count ){
        if(curr == nums.size()){
            if( currOr > maxi ){
                maxi = currOr;
                count = 1;
            }
            else if( currOr == maxi ){
                count++;
            }
            return;
        }
   
        //dont take
        dfs( nums, currOr, curr+1, count);
        
       
        // take
        dfs( nums, currOr|nums[curr], curr+1, count );
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int count = 0;
        dfs( nums, 0, 0, count );
        return count;
    }
};