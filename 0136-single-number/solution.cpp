class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int copu = nums[0];
        for(int i=1;i<nums.size();i+=2){
            if(nums[i]==copu){
                copu=nums[i+1];
            }
            else{
                break;
            }
        }
        return copu;
    }
};
