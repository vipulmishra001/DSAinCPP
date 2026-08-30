class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        // Find indices of min and max elements
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        
        // Ensure minIndex <= maxIndex for easier handling
        if (minIndex > maxIndex) swap(minIndex, maxIndex);
        
        // Three possible strategies:
        // 1. Remove both from the front
        int front = maxIndex + 1;
        
        // 2. Remove both from the back
        int back = n - minIndex;
        
        // 3. Remove one from front and one from back
        int mixed = (minIndex + 1) + (n - maxIndex);
        
        // Return the minimum of the three
        return min({front, back, mixed});
    }
};
