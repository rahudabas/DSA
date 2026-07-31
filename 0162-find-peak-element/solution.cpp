class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n>1 && nums[0]>nums[1])return 0;
        if(n>1 && nums[n-1]>nums[n-2])return n-1;

        int low=1;
        int high=n-2;
        if(n==1)return 0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int l= mid==0 ? nums[0] : nums[mid-1];
            int h= mid==n-1 ? nums[n-1] : nums[mid+1];

            if(nums[mid]>l && nums[mid]>h)return mid;
            else if(nums[mid]>l)low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};
