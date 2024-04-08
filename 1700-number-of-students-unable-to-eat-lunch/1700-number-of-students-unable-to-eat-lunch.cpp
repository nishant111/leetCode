class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        for(auto elem:students){
            stu.push(elem);
        }
        int top = 0;
        while(!stu.empty()){
            if(sandwiches[top] == stu.front()) {
                top++;
                stu.pop();
            }
            else{
                int size = stu.size();
                while(size>0 && stu.front()!=sandwiches[top]){
                    int curr = stu.front();
                    stu.pop();
                    stu.push(curr);
                    size--;
                }
                if(size == 0 && stu.front()!=sandwiches[top])
                    return stu.size();
            }
        }
        return 0;
        
    }
};