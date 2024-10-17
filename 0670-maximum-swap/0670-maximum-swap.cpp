class Solution {
public:
    int maximumSwap(int num) {
        int noToSwapl = -1;
        int noToSwapr = -1;
        int fir=-1;
        int fil=-1;
        int ir = 0;
        int curr = num;
        int il = 0;
        int idx = 0;
        string s = "";
        while( curr > 0 ){
            int digit = curr%10;
            if( digit > noToSwapl )
            {
                noToSwapl = digit;
                cout<<noToSwapl<<" left \n";
                il = idx;
            }
            if( noToSwapl != -1 && noToSwapl>digit){
                noToSwapr = digit;
                cout<<noToSwapr<<" right \n";
                ir = idx;
                fir = ir;
                fil = il;
                
            }
            idx++;
            curr = curr/10;
            s += char(digit+'0');
        }
        reverse(s.begin(), s.end());
        cout<<s<<"\n";
        if(fir!=-1 && fil!=-1){
            char t = s[s.size()-1-fil];
            s[s.size()-1-fil] = s[s.size()-1-fir];
            s[s.size()-1-fir] = t;
        }
        return stoi(s);
        
    }
};