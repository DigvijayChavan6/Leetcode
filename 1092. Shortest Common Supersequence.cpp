class Solution {
    // int getLen(string &a, string &b, int n, int m,
    // vector<vector<int>> &dp){
    //     if(n <= 0 || m <= 0)return 0;
        
    //     int cnt = 0;
        
    //     if(dp[n][m] != -1){
    //         return dp[n][m];
    //     }
        
    //     if(a[n-1] == b[m-1]){
    //         cnt = 1 + getLen(a, b, n-1, m-1, dp);
    //     }else{
    //         cnt = max(cnt, getLen(a, b, n-1, m, dp));
    //         cnt = max(cnt, getLen(a, b, n, m-1, dp));
    //     }
        
    //     return dp[n][m] = cnt;
    // }
  public:
    string shortestCommonSupersequence(string a, string b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int cnt = 0;
                if(a[i-1] == b[j-1]){
                    cnt = 1 + dp[i-1][j-1];
                }else{
                    cnt = max(cnt, dp[i-1][j]);
                    cnt = max(cnt, dp[i][j-1]);
                }
                
                dp[i][j] = cnt;
            }
        }

        string answer = "";
        int i = n, j = m;

        while(i > 0 && j > 0){
            if(a[i-1] == b[j-1]){
                answer += a[i-1];
                i--;
                j--;
            }else if(dp[i][j-1] > dp[i-1][j]){
                answer += b[j-1];
                j--;
            }else{
                answer += a[i-1];
                i--;
            }
        }

        while(i > 0){
            answer += a[i-1];
            i--;
        }

        while(j > 0){
            answer += b[j-1];
            j--;
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};