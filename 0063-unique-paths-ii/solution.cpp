class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<int> prev(n,0);
        // dp[0][0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[0]=1;
                    continue;
                    }
                if(obstacleGrid[i][j]==1){
                    curr[j]=0;
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
