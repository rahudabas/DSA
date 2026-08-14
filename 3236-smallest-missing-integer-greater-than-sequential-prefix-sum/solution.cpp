class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        if(n==1)return nums[0]+1;
        int i=1;
        cnt+=nums[0];
        while(i<n){
            if(nums[i]==nums[i-1]+1){
                cnt+=nums[i];
                i++;
                continue;
            }
            else{
                break;
            }
            i++;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==cnt)cnt++;
        }

        return cnt;
    }
};
