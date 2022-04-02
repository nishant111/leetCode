class Solution {
public:
    static bool comp(const int &a, const int &b)
    {
        return a>b;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map <int, queue<int>> m;
        for(int i = 0;i<values.size();i++)
        {
            if(m.find(values[i])!=m.end())
            {
                m[values[i]].push(i);
            }
            else
            {
                m[values[i]].push(i);
            }
        }
        sort(values.begin(), values.end(), this->comp);
        unordered_map<int, int> freq;
        int iter=0;
        int sum = 0;
        int pickCount=0;
        while(iter<values.size())
        {
            int labelVal = labels[ m[values[iter]].front() ];
            if(freq.find(labelVal)!=freq.end() &&
                freq[ labelVal ] == useLimit)
            {
                //cant pick;
                m[values[iter]].pop();
                iter++;
            }
            else
            {
                cout<<"picked"<<values[iter]<<"\n";
                sum += values[iter];
                pickCount++;
                m[values[iter]].pop();
                freq[labelVal] += 1;
                iter++;
            }
            if(pickCount==numWanted)
                break;
        }
        return sum;
    }
};