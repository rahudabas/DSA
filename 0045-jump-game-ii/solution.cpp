class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int jumps=0;
        while(r<n-1){
            int fartest=0;
            for(int i=l;i<=r;i++){
                fartest=max(i+nums[i],fartest);
            }
            l=r+1;
            r=fartest;
            jumps++;
        }
        return jumps;
    }
};
