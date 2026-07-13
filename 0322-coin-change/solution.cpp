class Solution {
public:
    int rec(int ind,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(ind==0){
            if(target%coins[ind]==0)return dp[ind][target]= target/coins[ind];
            else dp[ind][target]= 1e9;
        }

        if(dp[ind][target]!=-1)return dp[ind][target];
        int take=1e9;
        if(target>=coins[ind])take=1+rec(ind,target-coins[ind],coins,dp);

        int nottake=rec(ind-1,target,coins,dp);

        return dp[ind][target]=min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans=rec(n-1,amount,coins,dp);
        if(ans>=1e9)return -1;
        return ans;
        
    }
};
