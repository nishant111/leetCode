#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = INT_MIN;
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
        return (ans == INT_MIN?0:ans);
    }
};