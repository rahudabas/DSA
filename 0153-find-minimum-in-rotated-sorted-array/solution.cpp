class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int mini=min(nums[low],nums[high]);

        while(low<=high){
            int mid=(low+high)/2;

            //left half is sorted
            if(nums[low]<=nums[mid]){
                if(mini>=nums[low]){
                    mini=nums[low];
                    low=mid+1;
                }
                else{
                    low=mid+1;
                }
            }
            //right half is sorted
            else{
                if(mini>=nums[mid]){
                    mini=nums[mid];
                    high=mid-1;
                }
                else{
                    high=mid-1;
                }
            }
        }
    return mini;
    }
};
