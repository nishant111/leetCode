class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        int left; int right;
        vector<vector<int>> ans;
        for(int i = 0;i<nums.size();i++)
        {
            left = i+1;
            right = nums.size()-1;
            int targ = (-1) * nums[i];
            
            if(nums[i] > 0) break;
            while(left<right)
            {
                if(nums[left] + nums[right] > targ)
                {
                    right--;
                }
                else if(nums[left] + nums[right] < targ)
                {
                    left++;
                }
                else
                {
                    vector<int> tmp{nums[i], nums[left], nums[right]};
                    ans.push_back(tmp);
                    //avoid dup 
                    while(left+1< nums.size() && 
                          nums[left]== nums[left+1])
                    {
                        left++;
                    }
                    left++;
                    while (right -1>=0 &&
                          nums[right] == nums[right-1])
                    {
                        right--;
                    }
                    right--;
                }
            }
            
            //avoid dup
            while(i+1<nums.size() &&
               nums[i] == nums[i+1])
            {
                i++;
            }
            
        }
        return ans;
    }
};