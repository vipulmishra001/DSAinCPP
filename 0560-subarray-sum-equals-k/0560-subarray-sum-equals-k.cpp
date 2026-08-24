#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find count of subarrays with sum equal to k
    int subarraySum(vector<int>& arr, int k) {
        // Size of the array
        int n = arr.size();

        // Initialize count of subarrays
        int count = 0;

        // Traverse all possible start indices
        for (int i = 0; i < n; i++) {
            // Initialize sum for current subarray
            int sum = 0;

            // Traverse all possible end indices from start
            for (int j = i; j < n; j++) {
                // Add current element to sum
                sum += arr[j];

                // If sum equals k, increment count
                if (sum == k) {
                    count++;
                }
            }
        }

        // Return total count of subarrays
        return count;
    }
};