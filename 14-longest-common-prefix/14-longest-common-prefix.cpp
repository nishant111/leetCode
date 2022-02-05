class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        for(int i=0;i<strs.size();i++)
        {
            if(i==0)
                longest = strs[i];
            else
            {
                int k=0;int l=0;
                while(k<longest.length() && l<strs[i].length())
                {
                    if(strs[i][l]!=longest[k])
                    {
                        break;
                    }
                    k++;l++;
                }
                longest = longest.substr(0, k);
            }
        }
        return longest;
    }
};