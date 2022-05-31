class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map <int, int> m;
        
        for(int i= 0;i<deck.size();i++)
        {
            m[deck[i]]++;
        }
        
        for(int x =2;x<=deck.size();++x)
        {
            if((deck.size() %x) == 0)
            {
                int breakflag = false;
                for(auto elem:m)
                {
                    if((elem.second %x) != 0)
                    {
                        breakflag = true;
                        break;
                    }
                }
                if(breakflag == true)
                    continue;
                else
                    return true;
            }
        }
        return false;
    }
};