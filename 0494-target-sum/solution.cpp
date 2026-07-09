class Solution {
public:
    int rec(int ind,int target,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(ind==n){
            if(target==0)return 1;
            return 0;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        int take=0;
        if(nums[ind]<=target)take=rec(ind+1,target-nums[ind], nums,dp);
        int nottake=rec(ind+1,target,nums,dp);

        return dp[ind][target]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        int toget=(target+tot)/2;
        if(abs(target) > tot) return 0;
        if((target + tot) % 2 != 0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(toget+1,-1));
        return rec(0,toget,nums,dp);
    }
};
