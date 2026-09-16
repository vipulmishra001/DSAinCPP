class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        vector<vector<int>> prefix(n+1, vector<int>(k+1, 0));
        
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = (dp[i-1][j] + prefix[i-1][j-1]) % MOD;
            }
            for (int j = 0; j <= k; j++) {
                prefix[i][j] = (prefix[i-1][j] + dp[i][j]) % MOD;
            }
        }
        
        return dp[n][k];
    }
};
