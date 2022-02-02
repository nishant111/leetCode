#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int n, vector<string> &res, string help, int openCount, int closedCount)
    {
        if(openCount == closedCount && closedCount == n)
        {
            res.push_back(help);
            return;
        }
        else
        {
            if(openCount <n )
            {
                help.append("(");
                dfs(n, res, help, openCount+1, closedCount);
                help.pop_back();
            }
            if(closedCount < openCount)
            {
                help.append(")");
                dfs(n, res, help, openCount, closedCount+1);
                help.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string help;
        dfs(n,res,help, 0, 0);
        return res;
    }
};