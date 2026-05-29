class Solution {
public:

    int sumarr(vector<int>& nums){
        int sumi=0;
        for(int i=0;i<nums.size();i++){
            sumi+=nums[i];
        }
        return sumi;
    }

    int subarr_no(vector<int>& nums,int val){
        int cnt=1, sumi=0;
        for(int i=0;i<nums.size();i++){
            if(sumi+nums[i]<=val){
                sumi+=nums[i];
            }
            else{
                cnt++;
                sumi=nums[i];
            }
        }
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
       int low=*max_element(nums.begin(),nums.end());
       int high=sumarr(nums);

       while(low<=high){
        int mid=(low+high)/2;

        int cnt=subarr_no(nums,mid);

        if(cnt<=k){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
    return low; 
    }
};
