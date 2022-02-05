#include <bits/stdc++.h>
using namespace std;
//apply rabin karp

class Solution {
public:
    int hashFunction(string targ, int start, int end)
    {
        int hash= 0;
        for(int i =start;i<=end;i++)
        {
            hash = ( (hash*1 + targ[i]) );
        }
        cout << "hash is "<<hash<<"\n";
        return hash;
    }
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) return -1;
        int find = hashFunction(needle, 0 , needle.length()-1);
        
        //roll window and check for hash value
        int hash = hashFunction(haystack, 0, needle.length()-1);
        for(int i = 0;i<haystack.length()-needle.length() +1;i++)
        {
            if(hash == find)
            {
                //compare string
                int needleIter = 0;
                int hayIter = i;
                bool found = true;
                for(;needleIter<needle.length() && hayIter<haystack.length();needleIter++, hayIter++)
                {
                    if(needle[needleIter]!=haystack[hayIter])
                        found = false;
                }
                if(found == true)
                    return i;
            }
            hash = hash - (haystack[i] * pow(1, needle.length()-1) );
            hash = hash*1 + haystack[i+needle.length()];
        }
        return -1;
    }
};