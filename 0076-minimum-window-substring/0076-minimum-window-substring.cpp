class Solution {
public:
    bool mapsConditionIsSatisfied(unordered_map<char, int> ms, unordered_map<char, int> mt)
    {
        if(ms == mt) return true;
        for(auto elem : mt )
        {
            if(ms.find(elem.first)==ms.end()) 
                return false;
            else if(ms[elem.first]<elem.second)
                return false;
        }
        return true;        
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> mpt;
        unordered_map<char, int> mps;
        string ans = "";
        if(t.size()==0) return "";
        for(auto elem: t)
        {
            mpt[elem]++;
        }
        int matchCount = 0;
        int minSize = INT_MAX;
        int start = 0;
        int end = 0;
        while(end < s.size())
        {
            if(matchCount>=t.size()) // possible ans
            {
                while(matchCount>=t.size())
                {
                    if(mps.find(s[start])!= mps.end())
                    {
                        mps[s[start]]--;
                        if(mps[s[start]]<mpt[s[start]])
                            matchCount--;
                    }
                    start++;
                }
                if(s.substr(start-1, end-1-(start-1)+1).length()<minSize)
                {
                    ans = s.substr(start-1, end-1-(start-1)+1);
                    minSize = ans.size();
                }
                
            }
            if(mpt.find(s[end])!=mpt.end())
               {
                    if(mps[s[end]]<mpt[s[end]])
                        matchCount++;
                    mps[s[end]]++;
               }
            end++;
        }
        if(matchCount>=t.size()) // possible ans
        {
            while(matchCount>=t.size())
            {
                if(mps.find(s[start])!= mps.end())
                {
                    mps[s[start]]--;
                    if(mps[s[start]]<mpt[s[start]])
                        matchCount--;
                }
                start++;
            }
            if(s.substr(start-1, end-1-(start-1)+1).length()<minSize)
            {
                ans = s.substr(start-1, end-1-(start-1)+1);
                minSize = ans.size();
            }

        }
        return ans;
    }
};