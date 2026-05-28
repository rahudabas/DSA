class Solution {
public:
    long long hourtaken(vector<int>& arr,int speed){
        long long taken=0;
        for(int i=0;i<arr.size();i++){
            taken+= (arr[i]+speed-1)/speed;
        }
    return taken;
    }
    

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;

        while(low<=high){
            int mid = low + (high - low) / 2;;

            long long hourly= hourtaken(piles,mid);
            if(hourly<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
    return ans;
    }
};
