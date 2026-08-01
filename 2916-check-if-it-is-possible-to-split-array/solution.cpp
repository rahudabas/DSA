class Solution {
public:
    bool rec(int i,int j,int sumi,vector<int>& nums,int m,int con,vector<vector<int>>& dp){
        if(j-i==0)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(sumi!=con && sumi<m)return false;
        bool take_i= rec(i+1,j,sumi-nums[i],nums,m,con,dp);
        bool take_j=rec(i,j-1,sumi-nums[j],nums,m,con,dp);
        return dp[i][j]= take_i || take_j;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int sumi=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)sumi+=nums[i];  
        return rec(0,n-1,sumi,nums,m,sumi,dp); 
    }
};
