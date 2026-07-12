class Solution {
public:
    int rec(int i,int target,vector<int>&nums, vector<vector<int>>& dp){
        int n=nums.size();
        if(target==0)return dp[i][target]=true;

        if(i==n)return dp[i][target]=false;
        int take,nottake;

        if(dp[i][target]!=-1)return dp[i][target];
        if(nums[i]>target)take=false;
        else take=rec(i+1,target-nums[i],nums,dp);

        nottake=rec(i+1,target,nums,dp);

        return dp[i][target]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target;
        if(sum%2==1)return false;
        target=sum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        return rec(0,target,nums,dp);
    }
};
