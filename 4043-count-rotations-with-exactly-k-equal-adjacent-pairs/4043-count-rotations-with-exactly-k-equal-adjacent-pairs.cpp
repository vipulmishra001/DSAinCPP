class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        // Count equal ajacent pair of rotated string 
        int equal = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + 1) % n]) {
                equal++;
            }
        }

        if (k == equal - 1)
            return equal;

        if (k == equal)
            return n - equal;

        return 0;
    }
};