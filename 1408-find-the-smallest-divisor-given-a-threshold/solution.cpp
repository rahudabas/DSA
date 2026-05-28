class Solution {
public:
    int sumD(vector<int>& arr, int mid){
        int sumi=0;
        for(int i=0;i<arr.size();i++){

            sumi += (arr[i]+mid-1)/mid;
        }
        return sumi;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=*max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid=low+(high-low)/2;

            int a=sumD(nums,mid);
            if(a<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
