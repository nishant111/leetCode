class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int win = nums[0];
        int count = 1;
        for(int i = 1;i<nums.size();i++){
            if(win==nums[i] || win==INT_MIN){
                win = nums[i];
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                win = INT_MIN;
            }
        }
        return win;
    }
};