#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> deck;
        vector<int> output;
        // we will push index in the deck to be able to remove indexes that are out of the current window
        // set up the deck for the first k elements 
        for(int i = 0;i<k;i++)
        {
            //maintain decreasing sequence
            while(deck.empty()!=true && nums[deck.back()]<nums[i])
                deck.pop_back();
            deck.push_back(i);
        }
        bool first = true;
        //deck for ex 1 will now be
        // |1|2|
        for(int i = k;i<(nums.size());i++) //loop till end(keeping window size in mind)
        {
            
            output.push_back(nums[deck.front()]);
            //remove the out of scope indexes
            while(!deck.empty() && deck.front()<= i-k)
            {
                deck.pop_front();
            }
            while(!deck.empty() && nums[i]>=nums[deck.back()])
            {
                deck.pop_back();
            }   
            deck.push_back(i);
        }
        //push last max
        output.push_back(nums[deck.front()]);
        return output;
    }
};