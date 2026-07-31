class Solution {
public:
    int rec(int wt,vector<int>& nums){
        int n=nums.size();
        int ans=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            ans+=nums[i];
            if(ans>wt){
                ans=nums[i];
                cnt++;
            }
            // else if(ans==wt){
            //     cnt++;
            //     ans=0;
            // }
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=low+(high-low)/2;

            if(rec(mid,weights)<=days)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
