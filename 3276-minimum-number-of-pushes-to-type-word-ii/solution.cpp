class Solution {
public:
    int minimumPushes(string word) {
        vector<int> nums(26,0);
        int n=word.size();
        for(int i=0;i<n;i++){
            int rec=word[i]-'a';
            nums[rec]++;
        }

        sort(nums.begin(), nums.end(), greater<int>());
        int m=nums.size();

        int cnt=0;
        for(int i=0;i<m;i++){
            if(i<8)cnt+=nums[i];
            else if(i<16)cnt+=nums[i]*2;
            else if(i<24)cnt+=nums[i]*3;
            else cnt+=nums[i]*4;
        }
        return cnt;
    }
};
