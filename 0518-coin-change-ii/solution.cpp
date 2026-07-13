class Solution {
public:
    int rec(int ind,int target,vector<int>& coins, vector<vector<int>>& dp){
        if(ind==0){
            return dp[ind][target]=(target% coins[ind]==0);
        }

        if(dp[ind][target]!=-1)return dp[ind][target];

        int take=0;
        if(target>=coins[ind])take=rec(ind,target-coins[ind],coins,dp);
        int nottake=rec(ind-1,target,coins,dp);

        return dp[ind][target]=take+nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return rec(n-1,amount,coins,dp);
    }
};
