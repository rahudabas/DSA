class Solution {
public:
    long long hrtaken(vector<int>& piles, int mid){
        long long cnt=0;
        for(int i=0;i<piles.size();i++){
            cnt+=(piles[i]+mid-1)/mid; 
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=(low+high)/2;

            long long k=hrtaken(piles,mid);//hrs taken to eat banana with speed=mid

            if(k<=h){
                high=mid-1;
            }
            else low=mid+1;
        }
    return low;
    }
};
