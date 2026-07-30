class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;

        for(char c : s){
            if(c == '#'){
                if(!ss.empty())ss.pop();
            }else ss.push(c);
        }

        for(char c : t){
             if(c == '#'){
                if(!tt.empty())tt.pop();
            }
            else tt.push(c);
        }


        while(!ss.empty() && !tt.empty()){
            if(ss.top() == tt.top()){
                ss.pop(); tt.pop();
            }else{
                return false;
            }
        }

        return ss.empty() && tt.empty();
    }
};