class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for(auto elem:ops)
        {
            if(elem =="C")
            {
                record.pop_back();
            }
            else if(elem == "D")
            {
                record.push_back(record.back()*2);
            }
            else if(elem == "+")
            {
                int tmp1 = record.back();
                record.pop_back();
                int tmp2 = record.back();
                record.push_back(tmp1);
                record.push_back(tmp1+tmp2);
            }
            else
            {
                record.push_back(stoi(elem));
            }
        }
        int sum = 0;
        for(auto elem:record)
        {
            sum += elem;
        }
        return sum;
    }
};