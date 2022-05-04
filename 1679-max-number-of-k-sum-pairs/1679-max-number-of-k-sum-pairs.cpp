class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int , int> m;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] += 1;
        }
        
        for(auto elem:nums)
        {
            int target = k - elem;
            if(m[elem]==0) 
                continue;
            m[elem] -= 1;
            
            if(m[target]>0)
            {
                count++;
                m[target] -= 1;
            }
            else
            {
                m[elem] += 1;
            }
        }
        return count;
    }
};
























/*
O(nlogn) soln
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.size()-1;
        int count = 0;
        while(l<r)
        {
            if(nums[l] + nums[r] == k)
            {
                count += 1;
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < k)
            {
                l++;
            }
            else if (nums[l] + nums[r] > k)
            {
                r--;
            }
                
        }
        return count;
    }
};*/