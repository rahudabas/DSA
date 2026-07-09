class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[first],nums[i]);
                first++;
            }
        }
        // for(int j=first;j<n;j++){
        //     nums[j]=0;
        // }
    }
};
