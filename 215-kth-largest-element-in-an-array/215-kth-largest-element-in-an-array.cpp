#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> pq;
        for(int i = 0;i<nums.size();i++)
        {
            if(pq.size() <k)
            {
                pq.push(-1*nums[i]);
            }
            else if(pq.size()==k && nums[i]>(-1*pq.top()) )
            {
                pq.pop();
                pq.push(-1*nums[i]);
            }
        }
        return (-1 * pq.top() );
    }
};