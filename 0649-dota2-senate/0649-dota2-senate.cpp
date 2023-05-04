class Solution {
public:
    int count(string senate, char targ){
        int count = 0;
        for(auto elem:senate){
            if(elem==targ)
                count++;
        }
        return count;
    }
    void ban(string &senate, int startAt, char toBan, bool &loopedAround) {
        int ptr = startAt;
        while(1){
            if(ptr==0){
                loopedAround=true;
            }
            if(senate[ptr] == toBan){
                // deletes cgar at position ptr
                senate.erase(senate.begin()+ptr);
                return;
            }
            ptr = (ptr+1)%senate.size();
        }
    }
    string predictPartyVictory(string senate) {
        int countR = count(senate, 'R');
        int countD = count(senate, 'D');

        int iter = 0;
        while( countD>0 && countR>0){
            if(senate[iter] == 'R'){
                // must be one D either ahead or behind
                bool loopedAround = false;
                ban(senate, (iter+1)%senate.size(), 'D', loopedAround);
                countD--;
                if(loopedAround)
                {
                    // we removed 1 senator from behind , our index got adjusted
                    iter--;
                }
            }
            else if(senate[iter] == 'D') {
                // must be one R either ahed or behind
                bool loopedAround = false;
                ban(senate, (iter+1)%senate.size(), 'R', loopedAround);
                countR--;
                if(loopedAround)
                {
                    // we removed 1 senator from behind , our index got adjusted
                    iter--;
                }
            }
            iter = (iter+1)%senate.size();
        }
        if(countD==0)
            return "Radiant";
        else
            return "Dire";

    }
};