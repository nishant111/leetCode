#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m; 
        int left = 0;
        int right = nums.size()-1;
        for(int i = 0;i<nums.size();i++)
        {
            int find = target - nums[i];
            if(m.find(find)!=m.end() && m[find]!= i)
            {
                ans.push_back(i);
                ans.push_back(m[find]);
                break;
            }
            // if not found insert in the hash map, it will return
            // correct index later on.
            m.insert({nums[i], i});
        }
        return ans;
    }
};