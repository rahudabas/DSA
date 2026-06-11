class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        int maxlen=0;
        int cnt=0;

        while(r<n){
            if(nums[r]==0 && cnt<k){
                cnt++;
                int len=r-l+1;
                r++;
                maxlen=max(len,maxlen);
            }
            else if(nums[r]==0 && cnt==k){
                if(nums[l]==0){
                    l++;
                    cnt--;
                }
                else l++;
            }
            else if(nums[r]!=0){
                int len=r-l+1;
                r++;
                maxlen=max(len,maxlen);
            }

        }
    return maxlen; 
    }
};
