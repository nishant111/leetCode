class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int containsOne = false;
        for(int i = 0;i<nums.size();i++){
            int elem = nums[i];
            if(elem<0 || elem>n || elem == 1 || elem==0){
                if(elem==1)
                    containsOne = true;
                nums[i]=1;
            }
        }
        
        if(!containsOne)
            return 1;
        
        for(int i = 0;i<nums.size();i++){
            nums[abs(nums[i])%n] = abs(nums[abs(nums[i])%n]) * -1; 
        }
        for(int i = 1;i<nums.size();i++){
            if(nums[i]>0)
                return i;
        }
        return nums[0]>0?n:n+1;
    }
};