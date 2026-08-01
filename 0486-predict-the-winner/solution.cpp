class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(i==j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int take_i= nums[i] - solve(i+1,j,nums,dp); // jb iski next baari aayegi toh plus hojayega
        int take_j=nums[j] - solve(i,j-1,nums,dp);

        return dp[i][j]=max(take_i,take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(solve(0,n-1,nums,dp)>=0)return true;
        return false;
    }
};
