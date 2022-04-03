class Solution {
public:
    void reverse1(vector<int> &nums, int indx)
    {
        int left = indx;
        int right = nums.size()-1;
        while(left<=right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        
        int found = true;
        int indl=0;
        for(int i = nums.size()-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                indl = i-1;
                break;
            }
        }
        int ind2 = 0;
        for(int i = nums.size()-1;i>indl;i--)
        {
            if(nums[i]>nums[indl])
            {
                swap(nums[indl], nums[i]);
                reverse1(nums, indl+1);
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    void nextPermutation1(vector<int>& nums) {
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