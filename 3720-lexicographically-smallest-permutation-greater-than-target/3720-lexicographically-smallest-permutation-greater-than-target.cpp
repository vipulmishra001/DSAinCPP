class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int bestPos = -1;
        int bestChar = -1;

        // Try to match target from left to right.
        // At every position, see if we can put a slightly larger character.
        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            // Find a character greater than target[i]
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                    break;
                }
            }

            // We cannot continue matching target
            if (cnt[x] == 0) {
                break;
            }

            cnt[x]--;
        }

        // No permutation is greater than target
        if (bestPos == -1) {
            return "";
        }

        // Reset counts
        fill(cnt.begin(), cnt.end(), 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans;

        // Keep the prefix equal to target
        for (int i = 0; i < bestPos; i++) {
            ans += target[i];
            cnt[target[i] - 'a']--;
        }

        // Make the first difference
        ans += char('a' + bestChar);
        cnt[bestChar]--;

        // Fill the rest with smallest possible characters
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                ans += char('a' + c);
                cnt[c]--;
            }
        }

        return ans;
    }
};