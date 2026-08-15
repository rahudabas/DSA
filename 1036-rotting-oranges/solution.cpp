class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        while(!q.empty()){
            cnt++;
            int changes=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                        vis[nrow][ncol]=1;
                        changes++;
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                    }
                }
            }
            if(changes==0)cnt--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};
