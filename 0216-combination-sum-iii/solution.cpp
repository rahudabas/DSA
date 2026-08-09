class Solution {
public:
    void rec(vector<vector<int>>& ans,vector<int> res,int ind,int sum,int n,int k){
        if(sum==n){
            if(res.size()==k){
                ans.push_back(res);
            }
            return;
        }
        if(sum>n)return;
        if(ind>9){
            return;
        }
        res.push_back(ind);
        rec(ans,res,ind+1,sum+ind,n,k);
        res.pop_back();
        rec(ans,res,ind+1,sum,n,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        rec(ans,res,1,0,n,k);
        return ans;
    }
};
