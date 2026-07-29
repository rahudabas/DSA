class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int k=n-1;
            int j=i+1;
                while(j<k){
                    int sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];

                    if(sum==0){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1])j++;
                        while(j<k && nums[k]==nums[k+1])k--;
                    }
                    else if(sum>0)k--;
                    else j++;
            }
        }
        return ans;
    }
};
