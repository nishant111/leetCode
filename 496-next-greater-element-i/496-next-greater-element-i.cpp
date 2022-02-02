#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int , int> m;
        vector<int> res;
        stack<int> st;
        for(int i = 0;i<nums2.size();i++)
        {
            if(st.empty())
            {
                st.push(nums2[i]);
            }
            else if( nums2[i] > st.top())
            {
                // got answer for st.top()
                while(!st.empty() && nums2[i]>st.top())
                {
                    m.insert({st.top(),nums2[i]});
                    m[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
            else if(nums2[i]<st.top() )
            {
                st.push(nums2[i]);
            }
        }
        while(st.empty()!=true)
        {
            m[st.top()] = -1;
            st.pop();
        }
        
        // iterate nums1 and answers are already in nums2
        for(int i = 0;i<nums1.size();i++)
        {
            res.push_back(m.at(nums1[i]) ) ;
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int, int> m;
        vector<int> res;
        // putting nums2 in hashmap
        for(int i = 0;i<nums2.size();i++)
        {
            m[nums2[i]] = i;
        }
        
        for(int i = 0;i<nums1.size();i++)
        {
            bool found = false;
            for(int j = m[nums1[i]] + 1;j<nums2.size();j++)
            {
                if(nums2[j]> nums1[i])
                {
                    res.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if(found == false)
                res.push_back(-1);
        }
        
        return res;
        
    }
};*/