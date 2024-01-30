class Solution {
public:
    bool isOperator(string elem){
        if (elem=="+" || elem =="*" || elem=="-" || elem=="/")
            return true;
        return false;
    }
    int operate(int op1, int op2, string elem){
        if (elem == "+")
                return op1 + op2;
        if (elem=="*")
                return op1 * op2;
        if (elem =="-")
                return op1-op2;
        if (elem =="/")
                return op1/op2;
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto elem:tokens){
            if(isOperator(elem)){
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                st.push(operate(operand1, operand2, elem));
            }
            else{
                st.push(stoi(elem));
            }
        }
        return st.top();
    }
};