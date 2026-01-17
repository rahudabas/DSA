class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0, ele=0;

        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(ele==nums[i])ans++;
        }
        if(ans>nums.size()/2){
            return ele;
        }
        return -1;
    }
};
