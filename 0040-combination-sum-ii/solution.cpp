class Solution {
public:
    void rec(vector<vector<int>>& ans,vector<int> res,vector<int>& nums,int ind,int target){
        if(target==0){
            ans.push_back(res);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            if(nums[i]>target)break;
            res.push_back(nums[i]);
            rec(ans,res,nums,i+1,target-nums[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {  
        vector<vector<int>> ans;
        vector<int> res;
        sort(candidates.begin(),candidates.end());
        rec(ans,res,candidates,0,target);
        return ans;
    }
};
