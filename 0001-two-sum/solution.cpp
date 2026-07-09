class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int sumi=0;

        for(int i=0;i<n;i++){
            sumi=nums[i];
            // if(sumi==target)return{0,i};

            if(mp.find( target -sumi)!=mp.end()){
                return{mp[target - sumi],i};
            }
            else{
                mp[sumi]=i;
            }
        }
        return{-1,-1};
    }
};
