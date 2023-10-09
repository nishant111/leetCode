class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> ans;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                if( (mid-1>=0 && nums[mid-1]!=target) || mid == 0 ){
                    ans.push_back(mid);
                    break;
                }
                else{
                    r = mid-1;
                }
            }
            else if(target > nums[mid]){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        l = 0;
        r = nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                if( (mid+1<nums.size() && nums[mid+1]!=target) || mid == nums.size()-1 ){
                    ans.push_back(mid);
                    break;
                }
                else{
                    l = mid+1;
                }
            }
            else if(target > nums[mid]){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if(ans.size()>0)
            return ans;
        return {-1,-1};
        
    }
};