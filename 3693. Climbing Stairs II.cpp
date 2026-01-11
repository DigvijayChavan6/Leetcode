class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev = 0;
        int prev2 = 0;
        int prev3 = 0;
        for (int i = 1; i <= n; i++) {
            int cost = INT_MAX;
            if (i - 1 >= 0) {
                cost = min(cost, prev + costs[i - 1] + 1 * 1);
            }
            if (i - 2 >= 0) {
                cost = min(cost, prev2 + costs[i - 1] +  2 * 2);
            }
            if (i - 3 >= 0) {
                cost = min(cost, prev3 + costs[i - 1] + 3 * 3);
            }
            prev3 = prev2;
            prev2 = prev;
            prev = cost;
        }
        return prev;
    }
};