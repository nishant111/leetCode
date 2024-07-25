class Solution {
public:
    vector<int> merge(vector<int> &l, vector<int> &r){
        int li = 0;
        int ri = 0;
        vector<int> ret;
        while(li<l.size() | ri<r.size()){
            if(li<l.size() && ri<r.size()){
                if(l[li]<=r[ri]){
                    ret.push_back(l[li++]);
                }
                else{
                    ret.push_back(r[ri++]);
                }
            }
            else if(li<l.size()){
                ret.push_back(l[li++]);
            }
            else{
                ret.push_back(r[ri++]);
            }
        }
        return ret;
    }
    
    vector<int> mergeSort(vector<int> &nums, int l, int r){
        if(l==r){
            return {nums[l]}; 
        }
        int mid = (l+r)/2;
        vector<int> left = mergeSort(nums, l, mid);
        vector<int> right = mergeSort(nums, mid+1, r);
        return merge(left,right);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};