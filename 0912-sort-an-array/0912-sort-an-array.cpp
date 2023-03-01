class Solution {
public:
    void merge(vector<int> & nums,vector<int> & left,vector<int> & right){
        int li = 0;
        int ri = 0;
        int ni = 0;
        while(li<left.size() && ri<right.size())
        {
            if(left[li] <= right[ri]){
                nums[ni++] = left[li++];
            }
            else {
                nums[ni++] = right[ri++];
            }
        }

        if(li<left.size()){
            while(li<left.size()){
                nums[ni++] = left[li++];
            }
        }
        else if(ri<left.size()){
            while(ri<right.size()){
                nums[ni++] = right[ri++];
            }
        }
        return;

    }
    vector<int> ms(vector<int> & nums, int l, int r){
        if(l==r)
        {
            return {nums[l]};
        }
        int mid = (l+r)/2;
        vector<int> left = ms(nums, l, mid);
        vector<int> right = ms(nums, mid+1, r);
        vector<int> merged(left.size() + right.size());
        merge(merged, left, right );
        return merged;
    }
    vector<int> sortArray(vector<int>& nums) {
        return ms(nums, 0, nums.size()-1);
    }
};