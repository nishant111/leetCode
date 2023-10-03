class Solution {
public:
    vector<int> findPossOptions(string col, char turn){
        if(col.size()<=2) return {};
        vector<int> ret;
        for(int i=1;i<col.size()-1;i++){
            if(turn == 'A'){
                if(col[i] == 'A' &&  col[i-1]=='A' && col[i+1]=='A')
                {
                    ret.push_back(i);
                }
            }
            else{
                if(col[i] == 'B' && col[i-1]=='B' && col[i+1]=='B')
                {
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
    
    bool AliceWins(string colors, char turn){
        vector<int> possibleOptions;
        if(turn == 'A'){
            possibleOptions = findPossOptions(colors, 'A');
            if(possibleOptions.size()==0) return false;
            for(auto elem:possibleOptions){
                string newColors = colors.substr(0,elem) + colors.substr(elem+1, colors.size()-elem);
                if(AliceWins(newColors, 'B') ) {
                    return true;
                }
            }
        }
        else
        {
            possibleOptions = findPossOptions(colors, 'B');
            if(possibleOptions.size()==0) return true;
            for(auto elem:possibleOptions){
                if(!AliceWins(colors.substr(0,elem) + colors.substr(elem+1, colors.size()-elem), 'A')){
                    return false;
                }
            }
            
        }
        return false;
    }
    bool winnerOfGame(string col) {
        int alice = 0;
        int bob = 0;
        for(int i=1;i<col.size()-1;i++){
            if(col[i] == 'A'){
                if(col[i-1]=='A' && col[i+1]=='A')
                {
                    alice++;
                }
            }
            else{
                if(col[i] == 'B' && col[i-1]=='B' && col[i+1]=='B')
                {
                    bob++;
                }
            }
        }
        return alice>bob;
        
        //return AliceWins(colors, 'A');
    }
};