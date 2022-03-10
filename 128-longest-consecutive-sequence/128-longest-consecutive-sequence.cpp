class Solution {
public:
    // remember to start iteration only if it is the start of a consecutive sequence
    // this has been ensured using check for s.find(nums[i]-1)
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s;
        int maxcount = 0;
        for(int i = 0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            int count = 1;
            int targ = nums[i]-1;
            if(s.find(targ)==s.end())
            {
                // this can be start of a possible consecutive seq.
                targ = nums[i]+1;
                while(s.find(targ)!=s.end())
                {
                    count++;
                    targ++;
                }
            }
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};


















/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<bool> vis(nums.size(), 0);
        unordered_map <int, int> m;
        int maxcount = 0;
        for(int i = 0;i<nums.size();i++)
        {
            m.insert({nums[i], i});
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            int count = 1;
            if(vis[i]!=0) continue;
            vis[i] = 1;
            int targ = nums[i]-1;
            while(m.find(targ)!=m.end())
            {
                count++;
                vis[m[targ]] = 1;
                targ--;
            }
            maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};


*/



























/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> mySet;
        int numsSize = nums.size();
        for(int i = 0;i<numsSize;i++)
        {
            mySet.insert(nums[i]);
        }
        int longest = 0;
        for(int i = 0;i<numsSize;i++)
        {
            if(!mySet.count(nums[i]-1))
            {
                int currentNum = nums[i];
                int currentStreak = 1;
                while(mySet.count(currentNum+1))
                {
                    currentNum += currentNum;
                    currentStreak += currentStreak;
                }
                if(currentStreak > longest)
                    longest = currentStreak;
            }
        }
        return longest;
    }
};*/