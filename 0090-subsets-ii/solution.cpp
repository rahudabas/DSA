class Solution {
private:
    void findsubsets(int ind, vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        ans.push_back(ds);

        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;

            ds.push_back(nums[i]);
            findsubsets(i +1,nums,ds,ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        findsubsets(0,nums,ds,ans);
        return ans;
    }
};
