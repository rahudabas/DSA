class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,vector<vector<int>>& vis,int ogcol,int color){
        vis[row][col]=1;
        int n=image.size();
        int m=image[0].size();  
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            //isse hm neighbours m check krege
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && image[nrow][ncol]==ogcol){
                image[nrow][ncol]=color;
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,image,vis,ogcol,color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogcol=image[sr][sc];
        image[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        dfs(sr,sc,image,vis,ogcol,color);
        return image;
    }
};
