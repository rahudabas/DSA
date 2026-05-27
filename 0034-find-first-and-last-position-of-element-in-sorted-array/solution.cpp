class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        vector<int> ans;
        int k=-1;
        while(low<=high){
            int mid=(low+high)/2;
            //lower bound approach         
            if(nums[mid]==target){
                k=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        ans.push_back(k);
        int l=-1;
        low=0;
        high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            //lower bound approach         
            if(nums[mid]==target){
                l=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        ans.push_back(l);
    return ans;
    }
};
