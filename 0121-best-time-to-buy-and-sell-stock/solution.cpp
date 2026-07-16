class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int mini=prices[0];

        for(int i=0;i<n;i++){
            int cur=prices[i]-mini;
            ans=max(ans,cur);
            mini=min(mini,prices[i]);
        }
        return ans;
    }
};
