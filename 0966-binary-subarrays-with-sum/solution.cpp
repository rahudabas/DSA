class Solution {
public:
    int atmost(vector<int>& nums,int goal){
        if(goal<0)return 0;
        int l=0,r=0;
        int sum=0, cnt=0;

        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1; // jb sum bda ho toh window ko shrink krege na bhosde
            }
            cnt=cnt+(r-l+1);// abb sum shi hogya toh jitna subarray h usko add krege na
            
            r=r+1;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt1=atmost(nums,goal);
    int cnt2=atmost(nums,goal-1);
    return cnt1-cnt2;
    }
};
