class Solution {
public:
    int niceji(vector<int>& nums,int k){
        if(k<0)return 0;
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        int cnt=0;
        while(r<n){
            if(nums[r]%2==1)cnt++;
            while(cnt>k){
                if(nums[l]%2==1)cnt--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return niceji(nums,k)-niceji(nums,k-1);
    }
};
