#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixCount; 
        prefixCount[0] = 1; // base case

        int sum = 0, count = 0;
        for (int x : nums) {
            sum += x;

            // Check if (sum - k) exists in map
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }

            // Store current prefix sum
            prefixCount[sum]++;
        }
        return count;
    }
};
