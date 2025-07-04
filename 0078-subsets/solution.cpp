class Solution {
public:

    void helper(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &container){
        if(index == nums.size()){
            container.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        helper(index + 1, nums, ds, container);
        ds.pop_back();
        helper(index + 1, nums, ds, container);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> container;
        vector<int> ds;
        helper(0, nums, ds, container);
        return container;
    }
};
