class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int temp = 0;

        for(string c : tokens){
            if(c == "+"){
                temp = st.top();
                st.pop();
                temp += st.top();
                st.pop();
                st.push(temp);
            }else if(c == "-"){
                temp = st.top();
                st.pop();
                temp = st.top() - temp;
                st.pop();
                st.push(temp);
            }else if(c == "*"){
                temp = st.top();
                st.pop();
                temp = st.top() * temp;
                st.pop();
                st.push(temp);
            }else if(c == "/"){
                temp = st.top();
                st.pop();
                temp = st.top() / temp;
                st.pop();
                st.push(temp);
            }else{
                st.push(stoi(c));
            }
        }

        return st.top();
    }
};