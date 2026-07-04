class Solution {
public:
    //Memoization
    // int rec(int m,int n,vector<vector<int>>& dp){
    //     if(m==0 && n==0)return 1;
    //     if(m<0 || n<0)return 0;

    //     if(dp[m][n]!=-1)return dp[m][n];
    //     int left=rec(m,n-1,dp);//hm left m jayege toh col. reduce hoga
    //     int right=rec(m-1,n,dp);

    //     return dp[m][n]=left+right;
    // }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return rec(m-1,n-1,dp);
        vector<int> prev(n,0);
        // dp[0][0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[0]=1;
                    continue;
                    }
                int left=0;
                int top=0;
                if(i>0)top=prev[j];
                if(j>0)left=curr[j-1];

                curr[j]=top+left;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
