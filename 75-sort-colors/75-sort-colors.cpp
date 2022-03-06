class Solution {
public:
    void swap(vector<int>& nums, int left, int right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int two = nums.size()-1;
        int mid = 0;
        while(mid<=two)
        {
            if(nums[mid] == 0)
            {
                swap(nums, mid, zero);
                mid ++;
                zero++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums, mid, two);
                two--;
            }
        }
    }
};