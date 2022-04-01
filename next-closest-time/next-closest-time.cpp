class Solution {
public:
    string nextClosestTime(string time) {
        int val[4] = {2,4,6,9};
        unordered_set <char> st;
        int hr=0;
        int sec=0;
        
        int minutes = (((time[0]-'0')*10 + (time[1] -'0'))*60) + ((time[3]-'0')*10 + (time[4]-'0'));
        for(int i = 0;i<time.length();i++)
        {
            st.insert(time[i]);
            cout<<"inserted "<<time[i]<<"\n";
        }
        int newTime[4];
        while(true)
        {
           
            minutes = (minutes+1) % (24*60); //remeber to wrap arround to reset to 0000 if we exceed 24*60 minutes of the day
            int newTime[4] = {(minutes/60)/10, (minutes/60)%10, (minutes%60)/10, (minutes%60)%10}; //notice the conversion
             cout <<"newtime is "<<newTime[0]<<newTime[1]<<":"<<newTime[2]<<newTime[3]<<"\n";
            int fail = false;
            for(int i = 0;i<4;i++)
            {
                if(st.find(char(newTime[i]+'0'))==st.end())
                {
                    cout<<"didnt find "<<char(newTime[i]+'0')<<"\n";
                    fail = true;
                    break;
                }
            }
            if(fail == false)
            {
                string ans = "00:00";
                ans[0] = (newTime[0]+'0');
                ans[1] = (newTime[1] + '0');
                ans[3] = (newTime[2]+'0'); 
                ans[4] = (newTime[3] + '0');
                return ans;
            }
        }
    }
};