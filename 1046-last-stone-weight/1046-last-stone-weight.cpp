class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for(auto i:stones)
        {
            pq.push(i);
        }
        
        while(pq.size()>1)
        {
            int tmp1= pq.top();
            pq.pop();
            int tmp2 = pq.top();
            pq.pop();
            
            int newStone = abs(tmp1-tmp2);
            if(newStone>0)
            {
                pq.push(newStone);
            }
        }
        if(pq.size()==1) return pq.top();
        else
             return 0;
    }
};