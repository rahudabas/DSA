class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
                }
            //there can be one condition when low=mid=high, due to duplicacy so we not able to find sorted or not, so we trim the array

            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low=low+1;
                high=high-1;
                continue;
                //this continues trimming
            }
            //check left half sorted
            if(nums[low]<=nums[mid]){
                if(target<=nums[mid] && target>=nums[low]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //right half sorted
            else{
                if(target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }

            }
        }
        return false;
    }
};
