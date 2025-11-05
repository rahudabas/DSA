class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=nums.size();
        vector<int> arr(k);
        for(int i=0;i<k;i++){
            arr[i]=0;
        }
        int j=0;
        for(int i=0;i<k;i++){
            if(nums[i]!=0){
                arr[j]=nums[i];
                j++;
            }
        }

        for(int i=0;i<k;i++){
            nums[i]=arr[i];
        }
    }
};
