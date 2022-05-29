#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getState(string s)
    {
        int state = 0;
        for(int i = 0;i<s.length();i++)
        {
            int index = s[i] - 'a';
            state |= 1<<index;
        }
        return state;
    }
    int maxProduct(vector<string>& words) {
        int ans = INT_MIN;
        vector<int> state(words.size(), 0);
        for(int i = 0;i<words.size();i++)
        {
            state[i] = getState(words[i]);
        }
        
        for(int i = 0;i<state.size();i++)
        {
            for(int j = i+1;j<state.size();j++)
            {
                if((state[i] & state[j] ) == 0)
                {
                    int size = words[i].length() * words[j].length();
                    ans = max(size, ans);
                }
            }
        }
        if(ans == INT_MIN)
            return 0;
        return ans;
        
        
        /*
        TC: O(total words ^ 2)
        for(int i = 0;i<words.size();i++)
        {
            unordered_set <char>st;
            for(int j = 0;j<words[i].length();j++)
            {
                st.insert({words[i][j]});
            }
            for(int k = i+1;k<words.size();k++)
            {
                bool found=false;
                for(int l = 0;l<words[k].size();l++)
                {
                    if(st.find(words[k][l])!=st.end())
                    {
                        found = true;
                        break;
                    }
                }
                if(found == false)
                {
                    int size = (words[k].size() * words[i].size());
                    if(size > ans)
                        ans = size;
                }
            }
        }
        return (ans == INT_MIN?0:ans);*/
    }
};