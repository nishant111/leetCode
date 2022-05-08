#include <bits/stdc++.h>
using namespace std;
class item{
    public:
        string id;
        string content;
};

class Solution {
public:
    static bool comp(const item &a, const item &b)
    {
        if(a.content != b.content)
        {
            return a.content<b.content;
        }
        else
        {
            return a.id < b.id;
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digLog;
        vector<item> lettLog;
        vector<string> ans;
        for(int i = 0;i<logs.size();i++)
        {
            int j = 0;
            while(logs[i][j]!=' ')
            {
                j++;
            }
            if(logs[i][j+1] >= '0' && logs[i][j+1]<='9')
            {
                digLog.push_back(logs[i]);
            }
            else
            {
                item myItem;
                myItem.id = (logs[i]).substr(0, j);
                myItem.content = (logs[i]).substr(j+1, logs[i].size()-1);
                lettLog.push_back(myItem);
            }
        }
        sort(lettLog.begin(), lettLog.end(), comp);
        for(auto elem:lettLog)
        {
            ans.push_back(elem.id + ' ' + elem.content);
        }
        
        for(auto elem:digLog)
        {
            ans.push_back(elem);
        }
        return ans;
        
    }
};