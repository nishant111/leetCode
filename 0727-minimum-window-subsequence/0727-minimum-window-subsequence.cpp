class Solution {
public:
    string minWindow(string s1, string s2) {
         int l1 =0;
        int r1 = 0;
        int i2 = 0;
        string ans ="";
        unordered_set<int> st;
        for(;l1<s1.size();){
            if(s1[l1] == s2[i2]){
                i2++;
            }
            if(i2 == s2.size()) {
                int rev = l1;
                while(i2>0) {
                    if(s2[i2-1] == s1[rev]){
                        i2--;
                    }
                    rev--;
                }
                if(ans == "" || l1-rev<ans.size())
                {
                    ans = s1.substr(rev+1, l1-rev);
                }
                i2=0;
                l1 = rev+1;
            }
            l1++;
        }
        return ans;
    }
};



/*
class Solution {
public:
    string minWindow(string s1, string s2) {
        int l1 =0;
        int r1 = 0;
        int i2 = 0;
        string ans ="";
        unordered_set<int> st;
        for(;l1<s1.size();){
            if(s1[l1] == s2[i2]){
                int anotherPossibility = 0;
                r1 = l1+1;
                i2++;
                while(i2<s2.size() && r1<s1.size()) {
                    if(s1[r1] == s2[0]) {
                        // found new possible start, cache it
                        anotherPossibility = r1;
                    }
                    if(s1[r1] == s2[i2]){
                        i2++;
                    }
                    r1++;
                }
                if(i2==s2.size()){
                    // found all characters
                    string tmp = s1.substr(l1, r1-l1);
                    if(ans == "" || tmp.size()<ans.size())
                    {
                        ans = tmp;
                    }
                    if(anotherPossibility)
                    {
                        l1 = anotherPossibility;
                    }
                    else {
                        l1=r1;
                    }
                    i2=0;
                    r1=-1;
                }
                else {
                    // r1 reached end and counld not consume i2
                    break;
                }
            }
            else{
                l1++;
            }
        }
        return ans;
    }
};


*/