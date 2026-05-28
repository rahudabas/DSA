class Solution {
public:
    bool possible(vector<int>& arr,int day,int m,int k){
        int noB=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                //flower has bloomed
                cnt++;
            }
            else{
                //adding up bloomed consecutive flowers that can make buoquets
                noB+=cnt/k;
                cnt=0;
            }
        }
        noB+=cnt/k;

        if(noB>=m)return true;
        else return false;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end()), high = *max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid=low+(high-low)/2;

            if(1LL * m * k > bloomDay.size()) return -1;
            if(possible(bloomDay,mid,m,k)==true){
                high=mid-1;
                //cause we need minimum days
            }
            else{
                low=mid+1;
            }
        }
    return low;
    }
};
