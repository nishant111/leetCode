class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int i = 0;
        int j = 0;
        bool pick1 = true;
        while(i<word1.size() && j<word2.size()) {
            if(pick1)
            {
                res += word1[i++];
            }
            else
            {
                res += word2[j++];
            }
            pick1 =!pick1;
        }
        while(i<word1.size()) {
            res += word1[i++];
        }
        while(j<word2.size()) {
            res += word2[j++];
        }
        return res;
    }
};