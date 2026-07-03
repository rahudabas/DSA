class Solution {
public:
    int rec(int n,vector<int>& ans){
        if(n== 0)return ans[0]=1;
        if(n==1)return ans[1]=1;

        if(ans[n]!=-1)return ans[n];
        int left=rec(n-1,ans);
        int right =rec(n-2,ans);

        return ans[n]=left+right;
    }
    int climbStairs(int n) {
        vector<int> ans(n+1,-1);

        int cnt=rec(n,ans);
        return ans[n];
    }
};
