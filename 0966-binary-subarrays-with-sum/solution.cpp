class Solution {
public:
    int sumcnt(vector<int>& nums,int k){
        if(k<0)return 0;
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int cnt=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt1=sumcnt(nums,goal);
        int cnt2=sumcnt(nums,goal-1);
        return cnt1-cnt2;
    }
};
