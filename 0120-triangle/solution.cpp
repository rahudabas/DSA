class Solution {
public:
    //Memoization
    // int rec(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    //     int n=triangle.size();

    //     if(i==n-1)return triangle[n-1][j];
    //     // if(j>=m || j<0)return 1e9; // its not needed hoga hi nhi

    //     if(dp[i][j]!=INT_MAX)return dp[i][j];

    //     int down=triangle[i][j]+ rec(i+1,j,triangle,dp);
    //     int dig=triangle[i][j]+ rec(i+1,j+1,triangle,dp);

    //     return dp[i][j]= min(down,dig);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        // return rec(0,0,triangle,dp);

        for(int i=0;i<m;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int dig=triangle[i][j] + dp[i+1][j+1];
                int down=triangle[i][j]+ dp[i+1][j];
                dp[i][j]=min(dig,down);
            }
        }
        return dp[0][0];
    }
};
