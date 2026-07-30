class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1;
        int suf=1;
        
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pref==0)pref=1;
            if(suf==0)suf=1;
            
            pref=pref*nums[i];
            suf=suf*nums[n-i-1];
            maxi=max(maxi,max(pref,suf));
        }
        return maxi;
    }
};
