class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for(char c : s){
            if(!st.empty()){
                if(st.top()-c == 32 || st.top()-c == -32){
                    st.pop();
                }else{
                    st.push(c);
                }
            }else{
                st.push(c);
            }
        }

        string answer = "";
        while(!st.empty()){
            answer = st.top() + answer;
            st.pop();
        }

        return answer;
    }
};