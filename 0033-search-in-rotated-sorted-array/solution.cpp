class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }

            //if left part is sorted
            if(nums[low]<=nums[mid]){
                if(nums[mid]>target && target>=nums[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //if right part is sorted
            else{
                if(nums[mid]<target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
    return -1;
    }
};
