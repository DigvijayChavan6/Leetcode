class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    int getCount(int i, int n, string &s, vector<int> &dp){
        if(i == n)return 0;
        if(dp[i] != -1)return dp[i];
        int minCnt = INT_MAX;
        int cnt = 0;
        for(int j = i; j < n; j++){
            if(isPalindrome(i, j, s)){
                cnt = 1 + getCount(j+1, n, s, dp);
            }
            minCnt = min(minCnt, cnt);
        }
        return dp[i] = minCnt;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return getCount(0, n, s, dp) - 1;
    }
};

class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    // int getCount(int i, int n, string &s, vector<int> &dp){
    //     if(i == n)return 0;
    //     if(dp[i] != -1)return dp[i];
    //     int minCnt = INT_MAX;
    //     int cnt = 0;
    //     for(int j = i; j < n; j++){
    //         if(isPalindrome(i, j, s)){
    //             cnt = 1 + getCount(j+1, n, s, dp);
    //         }
    //         minCnt = min(minCnt, cnt);
    //     }
    //     return dp[i] = minCnt;
    // }
public:
    int minCut(string s) {
        int n = s.size();
        //vector<int> dp(n, -1);
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            int minCnt = INT_MAX;
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(isPalindrome(i, j, s)){
                    cnt = 1 + dp[j+1];
                }
                minCnt = min(minCnt, cnt);
            }
            dp[i] = minCnt;
        }

        return dp[0] - 1;
    }
};