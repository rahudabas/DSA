class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0;
        int cnt=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt++;
                ele=nums[i];
            }
            else{
                if(nums[i]!=ele){
                    cnt--;
                }
                else{
                    cnt++;
                }
            }
        }
        return ele;
    }
};
