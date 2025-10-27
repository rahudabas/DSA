class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int k = 0;
    if(nums.size()<=1){
        k++;
    }
    else{
    for(int i=0;i<nums.size() - 1;i++){
        if(nums[i]!=nums[i+1]){
            nums[k]=nums[i];
            k++;
        }
    }
    nums[k]=nums.back();
    k++;
    }
    return k;
} 
};
