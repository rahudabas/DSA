class Solution {
public:
    int oddfunc(int x){
        if(x%2==0)return 0;
        return 1;
    }
    int atmost(vector<int>& nums,int k){
        if(k<0)return 0;

        int l=0,r=0;
        int cnt=0, ans=0;

        while(r<nums.size()){
            cnt = (oddfunc(nums[r]) == 1) ? cnt + 1 : cnt;
            
            while(cnt>k){
                cnt = (oddfunc(nums[l])==1) ? cnt-1:cnt;
                l++;                
            }

            ans=ans+(r-l+1);
            r=r+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};
