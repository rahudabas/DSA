class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& adj,vector<vector<int>>& vis){
        queue<pair<int,int>> q;
        q.push({i,j});
        int n=adj.size();
        int m=adj[0].size();
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto row=q.front().first;
            auto col=q.front().second;
            q.pop();
            for(int l=0;l<4;l++){
                int nrow=row+drow[l];
                int ncol=col+dcol[l];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]!=1){
                    if(adj[nrow][ncol]=='1'){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                    else{
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1 && grid[i][j]=='1'){
                    vis[i][j]=1;
                    bfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
