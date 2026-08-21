class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        auto count = [&](long long x) {
            long long res = 0;
            // Inclusion-Exclusion over subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = gcd(lcm, (long long)coins[i]);
                        long long tmp = lcm / g * coins[i];
                        if (tmp > x) { overflow = true; break; }
                        lcm = tmp;
                    }
                }
                if (!overflow) {
                    int bits = __builtin_popcount(mask);
                    long long add = x / lcm;
                    if (bits % 2) res += add;
                    else res -= add;
                }
            }
            return res;
        };
        
        long long lo = 1, hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (count(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
