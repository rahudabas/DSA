class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0, high=n-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        int cnt=high, low1=0,high1=m-1;

        while(low1<=high1){
            int mid=(low1+high1)/2;
            if(high<0)return false;

            if(matrix[cnt][mid]==target)return true;
            else if(matrix[cnt][mid]<target){
                low1=mid+1;
            }
            else high1=mid-1;
        }
        return false;
    }
};
