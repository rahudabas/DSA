class Solution {
public:

    int maxelementincol(vector<vector<int>>& mat,int mid,int m){
        int maxi=INT_MIN;
        int cnt=0;
        for(int i=0;i<m;i++){
            if(mat[i][mid]>maxi){
                cnt=i;
                maxi=mat[i][mid];
            }
        }

        return cnt;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int low=0,high=n-1;
        vector<int> ans;


        while(low<=high){
            int mid=(low+high)/2;
            int row=maxelementincol(mat,mid,m);

            int left=-1, right=-1;
            
            if(mid-1>=0) {left=mat[row][mid-1];}

            if(mid+1<n) {right=mat[row][mid+1];}
            
            if(mat[row][mid]>left && mat[row][mid]>right){
                ans.push_back(row);
                ans.push_back(mid);
                return ans;
            }

            if(mat[row][mid]<left){
                high=mid-1;//toh peak element left side hoga
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
