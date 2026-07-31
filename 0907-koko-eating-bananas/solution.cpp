class Solution {
public:
    long long rec(int mid,vector<int>& piles){
        long long cnt=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]%mid==0)cnt+=piles[i]/mid;
            else cnt+=piles[i]/mid +1;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(rec(mid,piles)<=h)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
