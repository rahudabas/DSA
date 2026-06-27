class Solution {
public:
    //bfs approach , kahn' algo finding topo sort and it would be answer cause it removes cyclic part which cant be safe nodes

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revgraph(n);
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            // i->it
            // it>i  reversing the nodes link/adjacney list

            for(auto it: graph[i]){
                revgraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: revgraph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;

    }
};
