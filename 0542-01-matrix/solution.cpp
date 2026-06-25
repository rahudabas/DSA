class Solution {
public:
    void bfs(vector<vector<int>>& mat,vector<vector<int>>& vis,queue<pair<pair<int,int>,int>>& q,vector<vector<int>>& ans){

        int n=mat.size();
        int m=mat[0].size();
        int delrow[]={0,1,0,-1};
        int delcol[]={-1,0,1,0};


        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first.first;
            int col=node.first.second;
            int curcnt=node.second;

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    if(mat[nrow][ncol]==1){
                        int cnt=curcnt+1;
                        ans[nrow][ncol]=cnt;
                        q.push({{nrow,ncol},curcnt+1});
                        vis[nrow][ncol]=1;
                    }
                    else{
                        vis[nrow][ncol]=1;
                        q.push({{nrow,ncol},curcnt+1});
                    }
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int cnt=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,(vector<int>(m,0)));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        bfs(mat,vis,q,ans);

        return ans;
    }
};
