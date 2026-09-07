#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        // dp[i] = number of distinct subsequences till index i
        long long dp = 0;
        vector<long long> last(26, 0); // track subsequences ending with each char

        for (char c : s) {
            int idx = c - 'a';
            long long new_dp = (dp * 2 % MOD + 1 - last[idx] + MOD) % MOD;
            last[idx] = (dp + 1) % MOD; // subsequences ending with this char
            dp = new_dp;
        }

        return dp % MOD;
    }
};
