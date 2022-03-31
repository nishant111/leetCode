class Solution {
public:
    void printWords(vector<string> words)
    {
        for(auto it:words)
        {
            cout<<it<<"\n";
        }
    }
    string reorderSpaces(string text) {
        int countSpace = 0;
        int countWord = 0;
        vector<string> words;
        for(int i = 0;i<text.length();i++)
        {
            string word = "";
            if(text[i] == ' ')
            {
                countSpace++;
            }
            else
            {
                countWord ++;
                while(i+1<text.length() && text[i+1]!=' ')
                {
                    word += text[i];
                    i++;
                }
                word += text[i];
                words.push_back(word);
            }
        }
        printWords(words);
        int sbwCount=0;
        int saeCount=0;
        if(countWord > 1 && countSpace>=1 )
        {
            sbwCount = (countSpace/(countWord-1));
            saeCount = (countSpace%(countWord-1));
        }
        else if(countSpace > 0)
        {
            saeCount = countSpace;
        }
        string sbw="";
        string sae="";
        while(sbwCount-->0)
        {
            sbw += " ";
        }
        while(saeCount-->0)
        {
            sae += " ";
        }
        string ans = "";
        for(int i = 0;i<words.size();i++)
        {
            ans += words[i];
            if(i!=words.size()-1)
                ans += sbw;  // dont add space after the last word
        }
        
        return ans+sae;
    }
};