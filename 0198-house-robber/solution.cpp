class Solution {
public:
    //MEMOIZATION
    // int rec(int ind,vector<int>& dp,vector<int>& nums){
    //     if(ind==0)return nums[ind];
    //     if(ind<0)return 0;

    //     if(dp[ind]!=-1)return dp[ind];

    //     int take = nums[ind]+rec(ind-2,dp,nums);
    //     int not_take=0 + rec(ind-1,dp,nums);

    //     return dp[ind]=max(take,not_take);
    // }


    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        // return rec(n-1,dp,nums);
        dp[0]=nums[0];
        if(n>=2){
            dp[1]=max(dp[0],nums[1]);
        }

        //Tabultion
        // for(int i=2;i<n;i++){
        //         int take= nums[i] + dp[i-2];
        //         int not_take=dp[i-1];
        //         dp[i]=max(take,not_take);
        // }
        // return dp[n-1];

        int prev=nums[0];
        int prev2=0;
            for(int i=1;i<n;i++){
                int take= nums[i] + prev2;
                int not_take=prev;
                
                int curr=max(take,not_take);
                prev2=prev;
                prev=curr;
            }
        return prev;
    }
};
