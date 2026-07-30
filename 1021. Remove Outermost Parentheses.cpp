class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string answer = "";
        for(char c : s){
            if(c == '('){
                if(!st.empty()){
                    answer += "(";
                }
                st.push(c);
            }
            else{
                st.pop();
                if(!st.empty()){
                    answer += ")";
                }
            }
        }

        return answer;
    }
};