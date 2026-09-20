class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int revIndex = 26 - (s[i] - 'a'); // reversed alphabet index
            ans += revIndex * (i + 1);        // multiply by position (1-indexed)
        }
        return ans;
    }
};
