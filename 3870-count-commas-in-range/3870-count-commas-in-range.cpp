class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;

        // Numbers with 1 comma: [1000, 999999]
        if (n >= 1000) {
            ans += min(n, 999999) - 999;  // count of numbers with >=4 digits
        }

        // Numbers with 2 commas: [1,000,000, 999,999,999]
        if (n >= 1000000) {
            ans += (min(n, 999999999) - 999999) * 2;
        }

        // Numbers with 3 commas: [1,000,000,000, ...]
        if (n >= 1000000000) {
            ans += (n - 999999999) * 3;
        }

        return (int)ans;
    }
};
