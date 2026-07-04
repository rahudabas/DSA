class Solution {
public:
    int maxans(vector<int>& nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
            for(int i=1;i<n;i++){
                int take= nums[i] + prev2;
                int not_take=prev;
                
                int curr=max(take,not_take);
                prev2=prev;
                prev=curr;
            }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1,temp2;
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);//iss array m first k alawa elements hoge
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(maxans(temp1),maxans(temp2));
    }
};
