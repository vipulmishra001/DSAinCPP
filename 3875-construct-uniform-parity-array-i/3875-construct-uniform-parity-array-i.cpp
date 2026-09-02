class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        // Step 1: Check if all elements are already even or all odd
        bool allEven = true, allOdd = true;
        for (int x : nums1) {
            if (x % 2 == 0) allOdd = false;
            else allEven = false;
        }
        if (allEven || allOdd) return true;

        // Step 2: Otherwise, check if we can use differences
        // Observation: nums1[i] - nums1[j] has parity = parity(nums1[i]) ^ parity(nums1[j])
        // If nums1 contains both even and odd, then we can always form odd numbers
        // Example: even - odd = odd, odd - even = odd
        // So we can construct all odd array.
        return true;
    }
};
