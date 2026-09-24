class Solution {
public:
    // Count how many subarrays are needed if each subarray sum ≤ limit
    int countSubarrays(vector<int> &nums, int limit) {
        int subarrays = 1;
        long long currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(currSum + nums[i] <= limit) {
                currSum += nums[i];
            } else {
                subarrays += 1;
                currSum = nums[i];
            }
        }
        return subarrays;
    }

    int splitArray(vector<int> &nums, int k) {
        if(k > nums.size()) return -1;
        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);

        while(low <= high) {
            long long mid = (low + high) / 2;
            int subarrays = countSubarrays(nums, mid);

            if(subarrays > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
