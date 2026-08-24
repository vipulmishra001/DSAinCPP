#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Step 1: Compute prefix sums
        vector<int> prefix(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + stones[i];
        }

        // Step 2: DP backward pass
        // dp[i] = maximum score difference starting from index i
        int best = prefix[n-1];  // base case: must take all stones
        for (int i = n-2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }

        return best;
    }
};
