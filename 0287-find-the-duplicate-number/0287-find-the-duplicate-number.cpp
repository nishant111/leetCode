class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Approach 1 : treat nums as hash map, mark -1 on seeing
        // Approach 2 : treat nums as a linked list and detect cycle
        
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};