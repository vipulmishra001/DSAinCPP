class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int First = -1;
        int Last = -1;
        int n = nums.size();

        // Find first occurrence
        int low = 0, high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            {
                First = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0;
        high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            {
                Last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return {First, Last};
    }
};