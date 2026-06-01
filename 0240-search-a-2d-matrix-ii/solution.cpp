class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col=m-1;
        int row=0;

        while(col>=0 && row<n){
            if(matrix[row][col]==target)return true;
            if(matrix[row][col]>target){
                col--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};
