class Solution {
public:
    int lb(vector<int>& nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
    
    int ub(vector<int>& nums,int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target)low=mid+1;
            else if(nums[mid]>target)high=mid-1;
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return {lb(nums,target),ub(nums,target)-1};
            else if(nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};
