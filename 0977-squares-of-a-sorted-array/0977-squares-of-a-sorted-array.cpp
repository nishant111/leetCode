class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> t(nums.size());
        int start = 0;
        int end = nums.size()-1;
        int idx = end;
        while(start<=end){
            if( (nums[start]*nums[start]) >=(nums[end]*nums[end])){
                t[idx--]=nums[start]*nums[start];
                start++;
            }
            else{
                t[idx--]=nums[end]*nums[end];
                end--;
            }
        }
        return t;
    }
};