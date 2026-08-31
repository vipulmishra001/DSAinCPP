class Solution {
public:
    int findMin(vector<int>& nums) {
     int n=nums.size();
     int minm=INT_MAX;
     for(int i=0;i<n;i++)
     {
        if(nums[i]<minm)
            minm=nums[i];
     }
     return minm;
    }
};