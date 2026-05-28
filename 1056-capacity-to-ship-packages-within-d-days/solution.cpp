class Solution {
public:
    int sumall(vector<int>& nums){
        int sumi=0;
        for(int i=0;i<nums.size();i++){
            sumi+=nums[i];
        }
        return sumi;
    }

    int daystak(vector<int>& nums,int mid){
        int weight=0,cnt=1;

        for(int i=0;i<nums.size();i++){
            if(weight+nums[i]>mid){
                cnt++;
                weight=nums[i];
                //mtlb agr weight jyada h current k add hone s , toh next day m shift krdo usse, and weight m bhi value add krdena
            }
            else{
                weight+=nums[i];
            }
        }
        return cnt;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(),weights.end()), high=sumall(weights);

        while(low<=high){
            int mid=(low+high)/2;

            int a=daystak(weights,mid);
            if(a<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return low;
    }
};
