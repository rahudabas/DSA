class Solution {
public:
    int rec(vector<int>& nums,int k,int mid){
        int cnt=0;
        cnt= nums[0]<=mid ? 1:0;
        int ans=0;
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]<=mid)cnt++;
            else{
                //mtlb consecutive loop tut gya;
                ans+=cnt/k;
                cnt=0; //reset the bloom cnt
            }
        }
        ans+=cnt/k;
        return ans;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        if(1ll*m*k > n)return -1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(rec(bloomDay,k,mid)>=m)high=mid-1;
            else low=mid+1;
        }   
        return low;
    }
};
