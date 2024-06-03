class Solution {
public:
    int dfs(string &s, string &t, int si, int ti){
        if(ti==t.size()){
            return t.size();
        }
        
        if(si == s.size()){
            return ti;
        }
        int take = 0;
        int dontTake = 0;
        // take only in match case
        if(s[si] == t[ti]){
            take = dfs( s, t, si+1, ti+1 );
        }
        
        // dont take
        dontTake = dfs( s, t, si+1, ti );
        
        return max(take, dontTake);
    }
    int appendCharacters(string s, string t) {
        //vector<vector<int>> dp ( s.size(), vector<int>( t.size(), -1) );
        //return (t.size()-dfs(s, t, 0, 0 ));
        
        int si=0;
        int ti=0;
        while(si<s.size() && ti<t.size()){
            if(s[si]==t[ti]){
                si++;
                ti++;
            }
            else{
                si++;
            }
        }
        
        return (t.size() - ti);
    }
};