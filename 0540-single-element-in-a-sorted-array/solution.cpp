class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-1;

        while(low<=high){

            int mid=(low+high)/2;
            
            if(mid==0){
                return nums[0];
            }
            if(mid!=0 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }

            if(mid%2==0){
                if(nums[mid]==nums[mid-1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
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
