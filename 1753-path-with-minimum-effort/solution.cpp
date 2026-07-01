class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first; // in it we store max diff of the path
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();

            if(row==n-1 && col==m-1)return diff; // agr hmara destination top pr aagya, toh 
            // uska diff hi minimum hoga,uske baad waale jyada hoge

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int effort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                    if(effort< dist[nrow][ncol]){
                        dist[nrow][ncol]=effort;
                        pq.push({effort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
