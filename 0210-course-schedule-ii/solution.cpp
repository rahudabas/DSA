class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                //yeh edges ka collection diya h jisme 0->1
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(auto &it : prerequisites){
            int course = it[0];
            int prereq = it[1];

            adj[prereq].push_back(course);
            indegree[course]++;
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

            for(auto it:adj[node]){//hm jisko topo m daal diye uske adjacent k indegree reduce kro
                indegree[it]--;//jb remove krte toh adjacent ki indegree reduce krte
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        // sort(topo.begin(),topo.end());
        if(topo.size()==n)return topo;
        return{};
    }
};
