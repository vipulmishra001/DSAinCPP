class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, count = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1') count++;

            // shrink until window has exactly k ones
            while (count == k) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                } else if (len == minLen) {
                    string candidate = s.substr(left, len);
                    if (ans.empty() || candidate < ans) ans = candidate;
                }

                // move left to try shorter substring
                if (s[left] == '1') count--;
                left++;
            }
        }

        return ans;
    }
};
