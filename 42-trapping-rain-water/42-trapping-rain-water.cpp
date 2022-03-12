class Solution {
public:
    int towerL(int i , vector<int> &tower)
    {
        if(i == 0) return 0;
        int targ = tower[i];
        int ans = 0;
        i--;
        while(i>=0)
        {
            if(tower[i] > targ)
            {
                ans = max(ans, tower[i]);
            }
            i--;
        }
        return ans;
    }
    
    int towerR(int i , vector<int> &tower)
    {
        if(i == tower.size()-1) return 0;
        int targ = tower[i];
        int ans = 0;
        i++;
        while(i<tower.size())
        {
            if(tower[i] > targ)
            {
                ans = max(ans, tower[i]);
            }
            i++;
        }
        return ans;
    }
    
    void maxTowerOnLeft(vector<int> &MTOL, vector<int> &tower)
    {
        int maxYet = INT_MIN;
        
        for(int i = 0;i<tower.size();i++)
        {
            if(tower[i]>maxYet)
            {
                maxYet = tower[i];
            }
            if(maxYet > tower[i])
                MTOL[i] = maxYet;
        }
    }
    
    void maxTowerOnRight(vector<int> &MTOR, vector<int> &tower)
    {
        int maxYet = INT_MIN;
        for(int i = tower.size()-1;i>=0;i--)
        {
            if(tower[i]>maxYet)
            {
                maxYet = tower[i];
            }
            if(maxYet>tower[i])
                MTOR[i] = maxYet;
        }
    }
    
    int trap(vector<int>& tower) {
        int totalWater = 0;
        vector<int> MTOL (tower.size(), 0);
        vector<int> MTOR (tower.size(), 0);
        maxTowerOnLeft(MTOL, tower);
        maxTowerOnRight(MTOR, tower);
        for(int i = 0;i<tower.size();i++)
        {
            int water = 0;
            int mtol = MTOL[i];
            int mtor = MTOR[i];
            water = min(mtol, mtor) - tower[i];
            if(water < 0)
            {
                water = 0;
            }
            
            totalWater += water;
        }
        return totalWater;
    }
};