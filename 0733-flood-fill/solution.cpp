class Solution {
public:
    void bfs(vector<vector<int>>& image,vector<vector<int>>& vis,int sr,int sc,int color){
        int org=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();
        image[sr][sc]=color;
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto row=q.front().first;
            auto col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && image[nrow][ncol]==org){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bfs(image,vis,sr,sc,color);
        return image;
    }
};
