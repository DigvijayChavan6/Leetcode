class Solution {
  public:
    // Function to compute the edit distance between two strings
    int minDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<int> curr(m+1, 0), prev(m+1, 0);
        
        for(int j = 0; j <= m; j++){
            prev[j] = j;
        }
        
        for(int i = 1; i <= n; i++){
            curr[0] = i;
            for(int j = 1; j <= m; j++){
                
                int ins = INT_MAX, rem = ins, rep = ins, match = ins;
        
                if(s1[i-1] == s2[j-1]){
                    match = prev[j-1];
                }else{
                    ins = 1 + curr[j-1];
                    rem = 1 + prev[j];
                    rep = 1 + prev[j-1];
                }
        
                curr[j] = min(match, min(ins, min(rem, rep)));
            }
            prev = curr;
        }
        
        return prev[m];
    }
};