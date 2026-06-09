class Solution {
public:
    void combi(vector<int>& arr,int index, int target, vector<int>& nums,vector<vector<int>>& ans){
        if(index==arr.size()){
            if(target==0){
                ans.push_back(nums);
            }
            return;
        }

        if(arr[index]<=target){
            nums.push_back(arr[index]);
            combi(arr,index,target-arr[index],nums,ans);
            nums.pop_back();
        }

        combi(arr,index+1,target,nums,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> nums;
        vector<vector<int>> ans;
        int index=0;
        combi(candidates,index,target,nums,ans);
        return ans;
    }
};
