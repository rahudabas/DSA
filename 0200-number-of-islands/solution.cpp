class Solution {
public:
//     void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
//         vis[row][col]=1;
//         int n=grid.size();
//         int m=grid[0].size();

//         queue<pair<int,int>> q;
//         q.push({row,col});

//         while(!q.empty()){
//             int row=q.front().first;
//             int col=q.front().second;
//             q.pop();
//             int delrow[] = {-1,0,1,0};
//             int delcol[] = {0,1,0,-1};

//             for(int i=0;i<4;i++){
//                 int nrow = row + delrow[i];
//                 int ncol = col + delcol[i];

//                 if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='1'&& !vis[nrow][ncol]){
//                     vis[nrow][ncol]=1;
//                     q.push({nrow,ncol});
//                 }
//         }
//     }
// }
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();  
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='1'&& !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis);
            }
    }
    }    

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(vis[row][col]!=1 && grid[row][col]=='1'){
                    cnt++;
                    dfs(row,col,grid,vis);
                }
            }
        }
    return cnt; 
    }
};
