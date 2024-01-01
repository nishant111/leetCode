class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int cc=0;
        int ci=0;
        while(cc<g.size()&&ci<s.size()){
            if(s[ci]>=g[cc]){
                cc++;
            }
            ci++;
        }
        return cc;
    }
};