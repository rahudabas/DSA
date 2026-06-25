class Solution {
public:
    void bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>& q, int& maxcnt,vector<vector<int>>& vis){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        int row,col;

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<pair<int,int>,int> node=q.front();
                q.pop();
                row=node.first.first;
                col=node.first.second;
                int curcnt=node.second;
                maxcnt=max(maxcnt,curcnt);

                for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 &&!vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol},curcnt+1});
                        grid[nrow][ncol]=2;
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        bfs(grid,q,cnt,vis);

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
