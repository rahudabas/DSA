class Solution {
public:
    int rec(int mid,vector<int>& nums){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]+mid-1)/mid;
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid=low+(high-low)/2;

            if(rec(mid,nums)<=threshold)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
