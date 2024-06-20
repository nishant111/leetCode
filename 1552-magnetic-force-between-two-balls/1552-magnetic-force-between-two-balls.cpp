class Solution {
public:
    bool possibleToPlace( int force, vector<int>& position, int m){
        int lastPlaced = position[0];
        m--;
        for(int i = 1;i<position.size();i++){
            if(m==0)
                return true;
            if((position[i]-lastPlaced)>=force)
            {
                lastPlaced=position[i];
                m--;
            }
        }
        return (m==0);
            
    }
    
    int maxDistance(vector<int>& position, int m) {
        int l = 0;
        sort(position.begin(), position.end());
        int r = position[position.size()-1];
        int ans;
        while(l<=r){
            int force = (l+r)/2;
            bool ret = possibleToPlace(force, position, m);
            if(!ret){
                r=force-1;
            }
            else{
                ans=force;
                l=force+1;
            }
        }
        return ans;
    }
};