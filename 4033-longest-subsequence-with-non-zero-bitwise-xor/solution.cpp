class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        bool nonzero=false;

        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            if(nums[i]!=0)nonzero=true;
        }
        if(nonzero==false)return 0;
        if(xr==0)return n-1;
        return n;
    }
};
