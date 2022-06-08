class MovingAverage {
public:
    int cap ;
    double sum = 0;
    queue<int> q;
    MovingAverage(int size) {
        cap = size;
    }
    
    double next(int val) {
        if(q.size() == cap)
        {
            int curr = q.front();
            q.pop();
            sum -= curr;
            q.push(val);
            sum += val;
        }
        else
        {
            q.push(val);
            sum += val;
        }
        return (double)sum/(double)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */