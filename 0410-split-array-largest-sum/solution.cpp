class Solution {
public:
    long long rec(long long lim,vector<int>& nums){
        int n=nums.size();
        int cnt=1;
        int dis=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]+dis>lim){
                cnt++;
                dis=nums[i];
            }
            else dis+=nums[i];
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=*max_element(nums.begin(),nums.end());  
        long long high=0;
        for(int i=0;i<n;i++){
            high+=nums[i];
        }

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(rec(mid,nums)<=k){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};
