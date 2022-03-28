class Solution {
public:
    /*void swap(vector<int> &nums, int left, int right)
    {
        int tmp = nums[left];
        nums[left]=nums[right];
        nums[right] = tmp;
    }
    void reverse(vector<int> &nums, int idx)
    {
        int left = idx;
        int right = nums.size()-1;
        while(left >right)
        {
            swap(nums, left, right);
            left++;
            right--;
        }
    }*/
    void nextPermutation(vector<int>& nums) {
        int ind1=-1;
        int ind2=-1;
        for(int i = nums.size()-2;i>=0;i--)
        {
            if(nums[i+1]>nums[i])
            {
                ind1 = i;
                break;
            }
            
        }
        if(ind1 == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        //swap
        for(int i = nums.size()-1;i>ind1;i--)
        {
            if(nums[i]>nums[ind1]){
                ind2 = i;
                break;
            }
        }
        swap(nums[ind1], nums[ind2]);
        reverse(nums.begin()+ind1 + 1, nums.end());
    }
};