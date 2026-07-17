class Solution {
public:
    int rec(int ind,int fee,int buy, vector<int>& prices,int n,vector<vector<int>>& dp){
        if(ind==n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];

        int profit=0;
        if(buy){
            profit= max( -prices[ind] -fee + rec(ind+1,fee,0,prices,n,dp), rec(ind+1,fee,1,prices,n,dp));
        }
        else{
            profit=max(prices[ind] + rec(ind+1,fee,1,prices,n,dp), rec(ind+1,fee,0,prices,n,dp));
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(0,fee,1,prices,n,dp);
    }
};
