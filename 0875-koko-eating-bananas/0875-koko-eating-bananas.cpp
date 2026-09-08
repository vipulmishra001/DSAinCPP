class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int low = 1, high = findMax(p);
        while (low <= high) {
            int mid = low + (high - low) / 2;  // safer than (low+high)/2
            long long totalH = CalTotalHours(p, mid);  // use long long
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int findMax(vector<int>& p) {
        int maxi = INT_MIN;
        for (int x : p) maxi = max(maxi, x);
        return maxi;
    }

    long long CalTotalHours(vector<int>& p, int hourly) {
        long long totalH = 0;
        for (int x : p) {
            totalH += (x + hourly - 1) / hourly;  // integer ceil division
        }
        return totalH;
    }
};
