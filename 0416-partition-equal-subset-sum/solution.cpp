class Solution {
public:
    bool rec(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
        int n=arr.size();
        if(ind==n){
            if(target==0)return true;
            return false;
        }
        if(dp[ind][target]!=-1)return dp[ind][target];
        if(target==0)return true;
        bool take=false;
        if(arr[ind]<=target)take=rec(ind+1,target-arr[ind],arr,dp);
        bool nottake=rec(ind+1,target,arr,dp);

        return dp[ind][target]=take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(int i=0;i<n;i++){
            target+=nums[i];
        }
        if(target%2==1)return false;
        target=target/2;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return rec(0,target,nums,dp);
    }
};
