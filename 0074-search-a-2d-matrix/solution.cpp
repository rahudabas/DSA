class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]>target)high=mid-1;
            else low=mid+1;
        }
        if(high<0)return false;
        int low1=0;
        int high1=m-1;
        while(low1<=high1){
            int mid=low1+(high1-low1)/2;
            if(matrix[high][mid]==target)return true;
            else if(matrix[high][mid]>target)high1=mid-1;
            else low1=mid+1;
        }
        return false;
    }
};
