class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int i=1;
        int prev=0;
        while(i<n){
            if(nums[i]==nums[prev])i++;
            else{
                nums[prev+1]=nums[i];
                prev=prev+1;
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};
