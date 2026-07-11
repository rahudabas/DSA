class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0;
        int row=matrix.size()-1;
        int col = matrix[0].size()-1;
        vector<int> ans;

        while(i<=row && j<=col){
            //left to right
            for(int k=j;k<=col;k++){
                ans.push_back(matrix[i][k]);
            }
            i++;

            //top to bottom
            for(int m=i;m<=row;m++){
                ans.push_back(matrix[m][col]);
            }
            col--;

            //right to left
            if(i<=row){
                for(int k=col;k>=j;k--){
                    ans.push_back(matrix[row][k]);
                }
                row--;
            }

            //bottom to top
            if(j<=col){
                for(int m=row;m>=i;m--){
                    ans.push_back(matrix[m][j]);
                }
                j++;
            }
        }
    return ans;
    }
};
