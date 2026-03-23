class Solution {
  public:
    int minInsertions(string str) {
        // complete the function here
        string pqr = str;
        reverse(str.begin(), str.end());
        
        int n = str.size();
        int answer = 0;
        vector<int> curr(n+1, 0), prev(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int cnt = 0;
                if(str[i-1] == pqr[j-1]){
                    cnt = 1 + prev[j-1]; 
                }else{
                    cnt = max(cnt, curr[j-1]);
                    cnt = max(cnt, prev[j]);
                }
                curr[j] = cnt;
            }
            prev = curr;
        }
        
        return n - curr[n];
    }
};