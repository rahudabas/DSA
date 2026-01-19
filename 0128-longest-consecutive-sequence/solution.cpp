class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        sort(nums.begin(),nums.end());
        int min = nums[0];
        int maxi =1;
        int count=1;

        for(int i=1;i<nums.size();i++){
            if(nums[i]==min){
                continue;
            }
            else if(nums[i]-min==1){
                min=nums[i];
                count++;
                maxi = max(maxi,count);
            }

            else{
                min=nums[i];
                count =1;
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};
