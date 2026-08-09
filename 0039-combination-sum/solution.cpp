class Solution {
public:
    void rec(vector<vector<int>>& ans,vector<int> res,vector<int>& nums,int sum,int i,int target){
        int n=nums.size();
        if(sum==target){
            ans.push_back(res);
            return;
        }
        if(i==n || sum>target)return;
        res.push_back(nums[i]);
        rec(ans,res,nums,sum+nums[i],i,target);
        res.pop_back();
        rec(ans,res,nums,sum,i+1,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        rec(ans,res,candidates,0,0,target);      
        return ans;
    }
};
