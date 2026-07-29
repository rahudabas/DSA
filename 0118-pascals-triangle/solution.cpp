class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> res;
        for(int i=1;i<=n;i++){
            vector<int> tmp;
            tmp.push_back(1);
            int ans=1;
            for(int j=1;j<i;j++){
                ans=ans*(i-j);
                ans=ans/j;
                tmp.push_back(ans);
            }
            res.push_back(tmp);
        }
    return res;
    }

};
