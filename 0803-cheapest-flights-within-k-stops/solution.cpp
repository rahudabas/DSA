class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n+1,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;//store dist,(node,stops taken);
        q.push({0,{src,0}});

        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<flights.size();i++){
            int row=flights[i][0];
            int col=flights[i][1];
            int wt=flights[i][2];
            adj[row].push_back({col,wt});
        }

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int cost=it.first;
            int node=it.second.first;
            int stops=it.second.second;

            if(stops>k)continue;

            for(auto it:adj[node]){
                int adjnode=it.first;
                int edw=it.second;

                if(cost +edw < dist[adjnode]){
                    dist[adjnode] = cost +edw;
                    q.push({dist[adjnode],{adjnode,stops+1}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
