class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int dif;
        int n=prices.size();

        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
                dif=prices[i]-mini;
                maxi=max(dif,maxi);
        }
        if(maxi==INT_MIN)return 0;
        return maxi;
    }
};
