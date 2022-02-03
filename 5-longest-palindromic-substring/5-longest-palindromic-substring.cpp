#include <bits/stdc++.h>
using namespace std;

/* take an element and expand from center */
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0;i<s.length();i++)
        {
            //odd length palindrome
            int left = i;
            int right = i;
            while(left>=0 && right < s.size() && s[left] == s[right])
            {
                if( (right-left+1)>ans.length() )
                {
                    //this is our new potention answer
                    ans.erase();
                    cout <<"Potential answer is "<< s.substr(left, right-left+1) <<"\n";
                    ans.append(s.substr(left, right-left+1));
                }
                left--; right++;
            }
    
            //even length palindrome
            left = i;
            right = i+1;
            while(left>=0 && right < s.size() && s[left] == s[right])
            {
                if( (right-left+1)>ans.length())
                {
                    //this is our new potention answer
                    ans.erase();
                    cout <<"Potential answer is "<< s.substr(left, right-left+1) <<"\n";
                    ans.append(s.substr(left, right-left+1));
                }
                left--; right++;
                
            }
        }
        return ans;
    }
};

//find possible palindrom substring if it is greater than the previous palindrome substring this could be our potential answer

/*
Below Brute force solution in n^3 and is giving tle

class Solution {
public:
    bool isP(string s, int left, int right )
    {
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void dfs (string &ans, string &s, int curr)
    {
        if(curr == s.size())
        {
            return;
        }
        for(int i = curr;i<s.length();i++)
        {
            if(isP(s, curr, i) && ans.length()<(s.substr(curr, i-curr+1)).length())
            {
                cout << "possible answer is " <<s.substr(curr, i-curr+1) <<"\n";
                ans.erase();
                ans.append(s.substr(curr, i-curr+1));
            }
            dfs(ans, s, curr+1);
        }
    }
    string longestPalindrome(string s) {
        string ans;
        dfs(ans, s, 0);
        return ans;
    }
}; */