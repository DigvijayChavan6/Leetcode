class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string op : operations){
            if(op == "+"){
                int last = st.top();
                st.pop();
                int sum = st.top() + last;
                st.push(last);
                st.push(sum);
            }else if(op == "D"){
                st.push(st.top() + st.top());
            }else if(op == "C"){
                st.pop();
            }else{
                st.push(stoi(op));
            }
        }

        int sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};