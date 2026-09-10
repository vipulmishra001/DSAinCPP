class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1ll*k*1ll;
        if(val>bloomDay.size())return -1;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        int low=mini,high=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k))
            {
                high=mid-1;
            }
            else low=mid+1;

        }return low;
    }
    bool possible(vector<int>&arr,int days,int m,int k)
    {
        int cnt=0;
        int noOfB=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=days)
            {
                cnt++;
                if(cnt==k)
                {
                    noOfB++;
                    cnt=0;
                }
            }
            else
            {
               
                cnt=0;
            }
            noOfB+=(cnt/k);
            
        }return noOfB>=m;
    }

};