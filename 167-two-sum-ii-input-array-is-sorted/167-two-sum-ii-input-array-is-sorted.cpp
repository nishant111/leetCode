class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        unsigned int lo = 0;
        unsigned int hi = numbers.size()-1;
        
        while(lo<hi)
        {
            if(numbers[lo] + numbers[hi] == target)
            {
                ans[0] = lo+1;
                ans[1] = hi + 1;
                return ans;
            }
            else if(numbers[lo] + numbers[hi] < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
        return ans;
    }
};