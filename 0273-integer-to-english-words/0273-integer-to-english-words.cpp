class Solution {
public:
    unordered_map<int, string> mp = {
        {0,""},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"}, {5,"Five"},{6,"Six"}, {7,"Seven"}, {8,"Eight"}, {9,"Nine"},{10,"Ten"},
        {11,"Eleven"}, {12,"Twelve"},{13,"Thirteen"},{ 14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"}, {18,"Eighteen"}, {19,"Nineteen"}, {20,"Twenty"},
        {30,"Thirty"}, {40,"Forty"}, {50,"Fifty"},  {60,"Sixty"},{70,"Seventy"},  {80,"Eighty"},  {90,"Ninety"}, {100,"Hundred"}, {1000,"Thousand"}, {1000000,"Million"},{1000000000,"Billion"},
    };
    
    
    
    string numberToWords(int num) {
        string ans = "";
        if(num == 0) return "Zero";
        if(num <= 19){
            return mp[num];
        }
        
        if(num>19 && num<=99){
            ans = mp[(num/10) * 10];
            if((num%10)>0)
                ans += " " + mp[num%10];
            return ans;
        }
        vector<int> ranges = {1000000000, 1000000, 1000, 100};
        for(auto div:ranges){
            int quotient = num/div;
            //cout<<mp[div] <<" "<<quotient <<"\n";
            if(quotient > 0){
                ans = numberToWords(quotient) + " " + mp[div];
                if(( num%div )>0){
                    ans += " " + numberToWords( num%div );
                }
                break;
            }
        }
        return ans;
    }
};