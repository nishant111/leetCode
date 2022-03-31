#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> map;
        for(int i = 0;i<s.length();i++)
        {
            map[s[i]]+=1;
        }
        for(int i = 0;i<t.length();i++)
        {
            if( map.find(t[i]) != map.end() )
            {
                map[t[i]]-=1;
                if(map[t[i]] == 0)
                    map.erase(t[i]);
            }
            else 
                return false;
                
        }
        if(map.size()==0) return true;
        else return false;
    }
};