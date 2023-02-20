class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left <= right)
        {
            int mid = (left + right)/2;
            if(target == nums[mid] )
                return mid;
            else if(mid +1 < nums.size() && target > nums[mid] && target >= nums[mid+1])
            {
                left = mid +1;
            }
            else if(mid +1 < nums.size() && target > nums[mid] && target < nums[mid+1]){
                return mid +1;
            }
            else if (mid +1 == nums.size() && target > nums[mid]){
                return mid +1;
            }
            else if(mid - 1 >= 0 && target < nums[mid] && target > nums[mid-1]){
                return mid;
            }
            else if(mid -1 >=0 && target < nums[mid] && target <= nums[mid-1])
            {
                right = mid -1;
            }
            else if(mid -1<0 && target < nums[mid]){
                return 0;
            }
        }
        return -1;
    }
};