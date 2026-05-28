class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=1;int high=nums.size()-2;
            if(nums.size()==1)return 0;
            if(nums[0]>nums[1])return 0;
            if(nums[nums.size()-1]>nums[nums.size()-2])return nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                //upslope h yeh and right side m h peak then
                low=mid+1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1]){
                //downslope h yeh and left side m h peak
                high=mid-1;
            }
            else if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                //minima pr h and dono side ho sakti h peak so kahi bhi chle jao
                high=mid-1;
            }
        }
    return -1;
    }
};
