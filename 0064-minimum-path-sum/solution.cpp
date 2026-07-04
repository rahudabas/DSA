class Solution {
public:
    // int rec(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //     if(n==0 && m==0)return grid[0][0];
    //     if(n<0 || m<0)return 1e9;

    //     if(dp[n][m]!=-1)return dp[n][m];

    //     int left=grid[n][m] + rec(n,m-1,grid,dp); // iss cell ka sum+jo sum left jaake a rha
    //     int top=grid[n][m] + rec(n-1,m,grid,dp);

    //     return dp[n][m]=min(left,top);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        // return rec(n-1,m-1,grid,dp);      

        dp[0][0]=grid[0][0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                int left=1e9;
                int top=1e9;
                if(j>0)left=grid[i][j]+dp[i][j-1];
                if(i>0)top=grid[i][j]+dp[i-1][j];
                dp[i][j]=min(left,top);
            }
        }
        return dp[n-1][m-1];
    }
};
