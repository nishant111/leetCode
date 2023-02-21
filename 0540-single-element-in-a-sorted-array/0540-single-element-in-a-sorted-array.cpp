class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid;
        //int mid = -1;
        while(l<r)
        {
            mid = (l+r)/2;
            if(nums[mid] == nums[mid-1])
            {
                if((mid- 2 - l+1)%2 != 0)
                {
                    r = mid -2;
                }
                else
                    l = mid+1;
            }
            if(nums[mid] == nums[mid+1])
            {
                if ( (r - (mid+2) + 1)%2 != 0 )
                {
                    l = mid +2;
                }
                else
                    r = mid -1;
            }
            else if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
        }
        return nums[l];
    }
    int singleNonDuplicate1(vector<int>& nums) {
        int mid;
        int start = 0;
        int end = nums.size() -1;
        while(start < end)
        {
            mid = (start + end)/2;
            // check for pair
            if(nums[mid] == nums[mid-1])
            {
                //find which segment is of odd length
                if ( ((mid-2) - start + 1 ) %2 != 0)
                    end = mid -2;
                else
                    start = mid +1;
            }
            else if(nums[mid] == nums[mid+1])
            {
                if( (end-(mid+2)+1) % 2 != 0) //if odd on right
                    start = mid + 2;
                else                        // odd segment is on left
                    end = mid - 1;
            }
            else if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
        }
        return nums[start];
    }
};