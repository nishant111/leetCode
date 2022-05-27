class Solution {
    
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> existingNums = new HashMap<>();
        int[] result = new int[2];
        
        for (int i = 0 ; i < nums.length ; i++) {
            
            if (existingNums.get(target - nums[i]) != null) {
                
                result[0] = existingNums.get(target - nums[i]);
                result[1] = i;
                break;
            } else {
                existingNums.put(nums[i], i);
            }
        }
        
        return result;
    }
}